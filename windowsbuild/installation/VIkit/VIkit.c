#include <windows.h>
#include <string.h>
#include <stdio.h>
#include "..\exdll\exdll.h"

/* Copy the VIkit directory to the Contrib directory where NSIS was installed
 * (typically C:\Program Files\NSIS\Contrib) and build the VIkit project to
 * create the VIkit DLL. Be sure to build in Release mode. 
 *
 * Once VIkit.dll is built, copy it into NSIS's Plugins directory
 * (typically C:\Program Files\NSIS\Plugins).
 */

/* Uncomment these definitions if you need to debug the functions.
#define DEBUG_GetPathToOlderConfigFiles
#define DEBUG_MigrateConfigFiles
*/

/******************************************************************************
 *
 * Purpose: Reads a string value from the Windows registry entry for the
 *          current version of VisIt.
 *
 * Programmer: Brad Whitlock
 * Date:       Mon Aug 26 13:08:21 PST 2002
 *
 * Input Arguments:
 *   which_root : The root key to open.
 *   key        : The key that we're looking for.
 *
 * Output Arguments:
 *   keyval : A string containing the value for the key. This memory is
 *            allocated regardless of whether or not the key is found and it
 *            should be freed by the caller.
 *
 * Modifications:
 *
 *****************************************************************************/

static int
ReadKeyFromRoot(HKEY which_root, const char *ver, const char *key, char **keyval)
{
    int  readSuccess = 0;
    char regkey[100];
    HKEY hkey;

    /* Try and read the key from the system registry. */
    _snprintf(regkey, 100, "VISIT%s", ver);
    *keyval = (char *)malloc(500);
    if(RegOpenKeyEx(which_root, regkey, 0, KEY_QUERY_VALUE, &hkey) == ERROR_SUCCESS)
    {
        DWORD keyType, strSize = 500;
        if(RegQueryValueEx(hkey, key, NULL, &keyType, *keyval, &strSize) == ERROR_SUCCESS)
        {
            readSuccess = 1;
        }

        RegCloseKey(hkey);
    }

    return readSuccess;
}

/******************************************************************************
 *
 * Purpose: Reads a string value from the Windows registry entry for the
 *          current version of VisIt.
 *
 * Programmer: Brad Whitlock
 * Date:       Mon Aug 26 13:08:21 PST 2002
 *
 * Input Arguments:
 *   key : The key that we're looking for.
 *
 * Output Arguments:
 *   keyval : A string containing the value for the key. This memory is
 *            allocated regardless of whether or not the key is found and it
 *            should be freed by the caller.
 *
 * Modifications:
 *   Brad Whitlock, Mon Jul 12 16:34:18 PST 2004
 *   I made it use ReadKeyFromRoot so we can check for VisIt information
 *   in a couple places. This is to avoid the situation where VisIt won't
 *   run when installed without Administrator access.
 *
 *****************************************************************************/

static int
ReadKey(const char *ver, const char *key, char **keyval)
{
    int retval = 0;

    if((retval = ReadKeyFromRoot(HKEY_CLASSES_ROOT, ver, key, keyval)) == 0)
        retval = ReadKeyFromRoot(HKEY_CURRENT_USER, ver, key, keyval);
    
    return retval;     
}

/******************************************************************************
 *
 * Purpose: Reads a directory and calls a callback function for each .ini
 *          or session file in the directory.
 *
 * Programmer: Brad Whitlock
 * Date:       Fri Jul 8 14:35:57 PST 2005
 *
 * Input Arguments:
 *   path   : The path to the directory where we should read files.
 *   cb     : The callback function to call.
 *   cbData : The callback function data.
 *
 * Modifications:
 *
 *****************************************************************************/

static void
HandleConfigFiles(const char *path, void (*cb)(const char *, void *), void *cbData)
{
    int pathlen = 0;
    WIN32_FIND_DATA fd;
    HANDLE dirHandle = INVALID_HANDLE_VALUE;
    char path2[1024], search[1024];    
    FILE *log = NULL;

    strcpy(path2, path);
    pathlen = strlen(path2);
    if(path2[pathlen-1] != '\\')
    {
        path2[pathlen] = '\\';
        path2[++pathlen] = '\0';
    }
    strcpy(search, path2);
    search[pathlen] = '*';
    search[pathlen+1] = '\0';

    log = (FILE *)(((void **)cbData)[0]);
    if(log != NULL)
       fprintf(log, "search = \"%s\"\n", search);

    /* List the files in the old path and for each one of them that starts
       with "config ", copy the file to the new directory.
     */
    dirHandle = FindFirstFile(search, &fd);
    if(dirHandle != INVALID_HANDLE_VALUE)
    {
        do
        {
            int len = strlen(fd.cFileName);
            char *ini = fd.cFileName + len-4;
            char *vses = fd.cFileName + len-5;
            char *vsesgui = fd.cFileName + len-5-4;

            if(log != NULL)
            {
                fprintf(log, "\t%s\n", fd.cFileName);
                if(ini >= fd.cFileName)     fprintf(log, "\t\t%s\n", ini);
                if(vses >= fd.cFileName)    fprintf(log, "\t\t%s\n", vses);
                if(vsesgui >= fd.cFileName) fprintf(log, "\t\t%s\n", vsesgui);
            }

            if((ini >= fd.cFileName && _stricmp(ini, ".ini") == 0)   ||
               (vses >= fd.cFileName && _stricmp(vses, ".vses") == 0) ||
               (vsesgui >= fd.cFileName && _stricmp(vsesgui, ".vses.gui") == 0)
              )
            {
                if(_strnicmp(fd.cFileName, "visit-config", 12) == 0)
                {
                    /* We want to skip visit-config files because those get
                     * updated each version and copying over them would be
                     * bad.
                     */
                    if(log != NULL)
                        fprintf(log, "Skipping %s\n", fd.cFileName);
                }
                else
                    (*cb)(fd.cFileName, cbData);
            }
        } while(FindNextFile(dirHandle, &fd));
        FindClose(dirHandle);
    }
    else
    {
       if(log != NULL)
           fprintf(log, "INVALID_HANDLE!\n");
    }
}

/******************************************************************************
 *
 * Purpose: Reads a directory and returns 1 if there are config files in it
 *          or 0 if there are no config files.
 *
 * Programmer: Brad Whitlock
 * Date:       Fri Jul 8 14:35:57 PST 2005
 *
 * Modifications:
 *
 *****************************************************************************/

static void
has_config_files(const char *filename, void *cbData)
{
    void **cbd = (void**)cbData;
    FILE *log = (FILE *)(cbd[0]);
    int *ival = (int *)(cbd[1]);
    
    if(log != NULL)
        fprintf(log, "%s\n", filename);

    *ival = 1;
}

static int
HasConfigFiles(const char *path, FILE *log)
{
    int  retval = 0;
    void *cbData[2];
    cbData[0] = (void *)log;
    cbData[1] = (void *)&retval;

    HandleConfigFiles(path, has_config_files, (void *)cbData);

    return retval;
}

/******************************************************************************
 *
 * Purpose: Copies config files from 1 directory to another directory.
 *
 * Programmer: Brad Whitlock
 * Date:       Fri Jul 8 14:35:57 PST 2005
 *
 * Modifications:
 *
 *****************************************************************************/

static void
copy_config_files(const char *filename, void *cbData)
{
    char oldFile[1024], toFile[1024];
    const char *oldpath = 0;
    const char *newpath = 0;
    int len = 0;

    FILE *log = (FILE *)(((void **)(cbData))[0]);
    oldpath = (const char *)(((void **)(cbData))[1]);
    newpath = (const char *)(((void **)(cbData))[2]);

    len = strlen(oldpath);
    if(oldpath[len-1] == '\\')
        _snprintf(oldFile, 1024, "%s%s",  oldpath, filename);
    else
        _snprintf(oldFile, 1024, "%s\\%s",  oldpath, filename);

    len = strlen(newpath);
    if(newpath[len-1] == '\\')
        _snprintf(toFile, 1024, "%s%s",  newpath, filename);
    else
        _snprintf(toFile, 1024, "%s\\%s",  newpath, filename);

    if(log != NULL)
        fprintf(log, "copy file %s to %s\n", oldFile, toFile);

    CopyFile(oldFile, toFile, FALSE);
}

static void
CopyConfigFiles(const char *oldpath, const char *newpath, FILE *log)
{
    void *cbData[3];
    cbData[0] = (void *)log;
    cbData[1] = (void *)oldpath;
    cbData[2] = (void *)newpath;

    HandleConfigFiles(oldpath, copy_config_files, (void *)cbData);
}

/******************************************************************************
 *
 * Purpose: Replaces a string in a file and resaves the file.
 *
 * Programmer: Brad Whitlock
 * Date:       Thu Mar 16 11:43:23 PDT 2006
 *
 * Modifications:
 *
 *****************************************************************************/

static void
ReplaceStringInFileEx(const char *filename, const char *S, const char *R)
{
    FILE *src = NULL;
#ifdef DEBUG_ReplaceStringInFileEx
    FILE *log = fopen("C:\\VisItDev1.5.1\\installation\\ReplaceStringInFileEx.log", "wt");
    fprintf(log, "ReplaceStringInFileEx(\"%s\", \"%s\", \"%s\")\n", filename, S, R);
#endif
    src = fopen(filename, "rt");
    if(src != NULL)
    {
        FILE *dest = NULL;
        int count = 0;
        char buffer[1024];
        char destfile[1024];
        int LS = strlen(S);
        int LR = (R != NULL) ? strlen(R) : 0;

#ifdef DEBUG_ReplaceStringInFileEx
        fprintf(log, "We were able to open %s\n", filename);
#endif

        _snprintf(destfile, 1024, "%s.tmp", filename);
        dest = fopen(destfile, "wt");
        if(dest == NULL)
        {
#ifdef DEBUG_ReplaceStringInFileEx
            fprintf(log, "We were not able to open %s\n", destfile);
            fclose(log);
#endif
            fclose(src);
            return;
        }

        while(1)
        {
            buffer[count] = fgetc(src);

            if(feof(src))
                break;

            if(count+1 == LS)
            {
                /* Our string has reached the size of the string that
                 * looking for. If it matches, write the replacement
                 * string. Otherwise, write the string in the buffer.
                 */
                if(strncmp(buffer, S, LS) == 0)
                {
                    if(R != NULL && LR >= 1)
                        fwrite(R, LR, 1, dest);
                }
                else
                    fwrite(buffer, LS, 1, dest);
                count = 0;
            }
            else if(buffer[count] != S[count])
            {
                /* Our string cannot match the string in the buffer
                 * so write out the buffer.
                 */
                fwrite(buffer, count+1, 1, dest);
                count = 0;
            }
            else
            {
                /* keep going. */
                ++count;
            }
        }

        fclose(src);
        fclose(dest);
#ifdef DEBUG_ReplaceStringInFileEx
        fprintf(log, "Closed src and dest\n");
#endif

        /* Try renaming the files. */
        if(remove(filename) == 0)
        {
            rename(destfile, filename);
#ifdef DEBUG_ReplaceStringInFileEx
            fprintf(log, "Renamed %s to %s\n", filename, destfile);
#endif
        }
#ifdef DEBUG_ReplaceStringInFileEx
        else
        {
            fprintf(log, "Could not remove %s\n", filename);
        }
#endif
    }
#ifdef DEBUG_ReplaceStringInFileEx
    else
    {
        fprintf(log, "Could not open %s\n", filename);
    }

    fclose(log);
#endif
}

/******************************************************************************
 ******************************************************************************
 ***
 *** NSIS EXTENSION FUNCTIONS
 ***
 ******************************************************************************
 *****************************************************************************/


/******************************************************************************
 *
 * Purpose: This function is a custom extension for the NSIS installer that
 *          allows it to easily format the install directory, stored in
 *          $INST_DIR, to a Java preference that we can use to poke VisIt's
 *          installation directory into the registry so Java can find it.
 *
 * Programmer: Brad Whitlock
 * Date:       Mon Jun 6 16:55:54 PST 2005
 *
 * Input Arguments:
 *
 * Input / Output Arguments:
 *
 * Output Arguments:
 *
 * Modifications:
 *
 *****************************************************************************/

void __declspec(dllexport) GetInstallPathFormattedForJava(
    HWND hwndParent, int string_size, 
    char *variables, stack_t **stacktop)
{
    char *path = 0, newpath[1024];
    int i, pos = 0, len = 0;

    EXDLL_INIT();

    if(!g_stacktop)
        return;

    path = getuservariable(INST_INSTDIR);

    newpath[0] = '\0';
    len = strlen(path);
    memset(newpath, 0, 1024);

    for(i = 0; i < len && pos < 1024; ++i)
    {
        char c = path[i];
        if(c == '\\')
        {
            newpath[pos++] = '/';
            c = '/';
        }
        else if(c >= 'A' && c <= 'Z')
            newpath[pos++] = '/';
        newpath[pos++] = c;
    }

    pushstring(newpath);
}


/******************************************************************************
 *
 * Purpose: This function is a custom extension for the NSIS installer that
 *          allows it to determine the path to the most recent older config
 *          files from previously installed versions of VisIt.
 *
 * Programmer: Brad Whitlock
 * Date:       Mon Jun 6 16:55:54 PST 2005
 *
 * Precondition:
 *   The string containing the current version of VisIt is to be passed on
 *   the stack.
 *
 * Postcondition:
 *   2 values are returned on the stack. The top value is the install path
 *   of the last version of VisIt to have config files that we want to
 *   copy. The value at top-1 in the stack is a message box prompt that is
 *   populated if we found config files.
 *
 *   If no config files were found for any version of VisIt, 2 blank strings
 *   are pushed onto the stack.
 *
 * Modifications:
 *
 *****************************************************************************/

void __declspec(dllexport) GetPathToOlderConfigFiles(
    HWND hwndParent, int string_size, 
    char *variables, stack_t **stacktop)
{
    /* The versions of VisIt table */
    const char *versionTable[] = {
    "1.5.5", "1.5.4", "1.5.3", "1.5.2", "1.5.1", "1.5",
    "1.4.5", "1.4.4", "1.4.3", "1.4.2", "1.4.1", "1.4",
    "1.3.5", "1.3.4", "1.3.3", "1.3.2", "1.3.1", "1.3"
    };
    const int nVersions = sizeof(versionTable) / sizeof(const char *);
    int  i, found = 0;
    char *installPath = 0;
    char currentVersion[100];
    char msg[1024];
    FILE *log = NULL;

    EXDLL_INIT();

    if(!g_stacktop)
        return;

    popstring(currentVersion);

#ifdef DEBUG_GetPathToOlderConfigFiles
    log = fopen("C:\\VIkit_GetPathToOlderConfigFiles.txt", "wt");
    if(log != NULL)
        fprintf(log, "currentVersion = \"%s\"\n", currentVersion);
#endif

    /* Look through the versions until we find one that is installed 
       that is not the current version. If we find one then push its
       installation directory onto the stack.
     */
    for(i = 0; i < nVersions; ++i)
    {
        if(strcmp(versionTable[i], currentVersion) < 0 &&
           ReadKey(versionTable[i], "VISITHOME", &installPath) != 0)
        {
            found = HasConfigFiles(installPath, log);
            if(found)
            {
                _snprintf(msg, 1024, "There are config files from VisIt %s. "
                    "Would you like to copy them to your new VisIt "
                    "installation?", versionTable[i]);
                pushstring(msg);
                pushstring(installPath);

#ifdef DEBUG_GetPathToOlderConfigFiles
                if(log != NULL)
                    fprintf(log, "msg=%s\ninstallPath=%s\n", msg, installPath);
#endif


                free(installPath);
                break;
            }
        }
    }

    /* If we did not find a current version then push an empty string
     * onto the stack.
     */
    if(!found)
    {
        pushstring("");
        pushstring("");

#ifdef DEBUG_GetPathToOlderConfigFiles
        if(log != NULL)
            fprintf(log, "No config files from older versions!\n");
#endif
    }

#ifdef DEBUG_GetPathToOlderConfigFiles
    if(log != NULL)
        fclose(log);
#endif
}


/******************************************************************************
 *
 * Purpose: This function is a custom extension for the NSIS installer that
 *          allows it to determine the path to the most recent older config
 *          files from previously installed versions of VisIt.
 *
 * Programmer: Brad Whitlock
 * Date:       Mon Jun 6 16:55:54 PST 2005
 *
 * Precondition:
 *   The string containing the path to the old version of VisIt must be on the
 *   top of the stack.
 *
 * Postcondition:
 *   The value is popped from the stack and config files are copied.
 *
 * Modifications:
 *
 *****************************************************************************/

void __declspec(dllexport) MigrateConfigFiles(
    HWND hwndParent, int string_size, 
    char *variables, stack_t **stacktop)
{
    char *newpath = 0;
    char oldpath[1024];
    FILE *log = NULL;
    EXDLL_INIT();

    if(!g_stacktop)
        return;

    /* Source directory. */
    popstring(oldpath);
    /* Destination directory. */
    newpath = getuservariable(INST_INSTDIR);

#ifdef DEBUG_MigrateConfigFiles
    log = fopen("C:\\VIkit_MigrateConfigFiles.txt", "wt");
    if(log != NULL)
    {
        fprintf(log, "oldpath = \"%s\"\n", oldpath);
        fprintf(log, "newpath = \"%s\"\n", newpath);
    }
#endif

    /* Copy the config files. */
    if(strlen(oldpath) > 0)
        CopyConfigFiles(oldpath, newpath, log);

#ifdef DEBUG_MigrateConfigFiles
    if(log != NULL)
        fclose(log);
#endif
}


/******************************************************************************
 *
 * Purpose: This function is a custom extension for the NSIS installer that
 *          allows it to replace a string in a file.
 *
 * Programmer: Brad Whitlock
 * Date:       Thu Mar 16 10:52:54 PDT 2005
 *
 * Precondition:
 *   The strings containing the filename, string to replace, and replacement
 *   string on the top of the stack.
 *
 * Postcondition:
 *   The arguments used to call this function are popped from the stack.
 *
 * Modifications:
 *
 *****************************************************************************/

void __declspec(dllexport) ReplaceStringInFile(
    HWND hwndParent, int string_size, 
    char *variables, stack_t **stacktop)
{
    char *path_file = NULL;
    char *installdir = NULL;
    char filename[1024];
    char stringtoreplace[1024];
    char replacementstring[1024];
    FILE *src = NULL;
    FILE *dest = NULL;
    int linstalldir;
    EXDLL_INIT();

    if(!g_stacktop)
        return;

    /* Replacement string. */
    popstring(replacementstring);
    /* String to replace. */
    popstring(stringtoreplace);
    /* Filename. */
    popstring(filename);

    /* Destination directory. */
    installdir = getuservariable(INST_INSTDIR);

    linstalldir = strlen(installdir);
    if(installdir[linstalldir-1] == '\\')
    {
        path_file = (char *)malloc(linstalldir + strlen(filename) + 1);
        sprintf(path_file, "%s%s", installdir, filename);
    }
    else
    {
        path_file = (char *)malloc(linstalldir + strlen(filename) + 1 + 1);
        sprintf(path_file, "%s\\%s", installdir, filename);
    }

    /* Replace the string in the specified file. */
    if(stringtoreplace != NULL && strlen(stringtoreplace) > 0)
        ReplaceStringInFileEx(path_file, stringtoreplace, replacementstring);
    
    free(path_file);
}

BOOL WINAPI DllMain(HANDLE hInst, ULONG ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}