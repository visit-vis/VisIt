#include <windows.h>
#include <string.h>
#include "..\exdll\exdll.h"

/* Copy the VIkit directory to the Contrib directory where NSIS was installed
 * and build the VIkit project to create the VIkit DLL. Be sure to build in
 * Release mode. Also, store the resulting DLL in NSIS's Plugins directory.
 */

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

BOOL WINAPI DllMain(HANDLE hInst, ULONG ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}