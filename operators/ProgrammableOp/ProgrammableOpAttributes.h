/*****************************************************************************
*
* Copyright (c) 2000 - 2015, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef PROGRAMMABLEOPATTRIBUTES_H
#define PROGRAMMABLEOPATTRIBUTES_H
#include <string>
#include <AttributeSubject.h>

#include "JSONNode.h"
#include <algorithm>
#include <cctype>
#include <locale>
#include <functional>

// ****************************************************************************
// Class: ProgrammableOpAttributes
//
// Purpose:
//    ProgrammableOpAttributes
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class ProgrammableOpAttributes : public AttributeSubject
{
public:
    int index;
    JSONNode script;

    // These constructors are for objects of this class
    ProgrammableOpAttributes();
    ProgrammableOpAttributes(const ProgrammableOpAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    ProgrammableOpAttributes(private_tmfs_t tmfs);
    ProgrammableOpAttributes(const ProgrammableOpAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~ProgrammableOpAttributes();

    virtual ProgrammableOpAttributes& operator = (const ProgrammableOpAttributes &obj);
    virtual bool operator == (const ProgrammableOpAttributes &obj) const;
    virtual bool operator != (const ProgrammableOpAttributes &obj) const;
private:
    void Init();
    void Copy(const ProgrammableOpAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectScriptMap();

    // Property setting methods
    void SetScriptMap(const std::string &scriptMap_);

    // Property getting methods
    const std::string &GetScriptMap() const;
          std::string &GetScriptMap();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    void AddConstant(const std::string& name, const std::string& constant);
    void AddFunction(const std::string& name, const stringVector& atts);
    void AddRScript(const std::string& name, const stringVector& atts, const std::string& code);
    void AddPythonScript(const std::string& name, const stringVector& atts, const std::string& code);
    void AddNode(const std::string& name, const std::string& type);
    void AddConnection(const std::string& from, const std::string& to, const std::string& portName);
    void AddFinalOutputConnection(const std::string &from);
    bool SetupPipeline(const JSONNode& atts, stringVector& args, const std::string &parent);
    void LoadRKernel(const std::string& name, const JSONNode& atts, const std::string& code);
    void LoadPythonKernel(const std::string& name, const JSONNode& atts, const std::string& code);
    std::string trim(const std::string &s);
    std::string rtrim(const std::string &ts);
    std::string ltrim(const std::string &ts);
    std::string getNextName();
    void replace(std::string& str, const std::string& oldStr, const std::string& newStr);

    // IDs that can be used to identify fields in case statements
    enum {
        ID_scriptMap = 0,
        ID__LAST
    };

private:
    std::string scriptMap;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define PROGRAMMABLEOPATTRIBUTES_TMFS "s"

#endif
