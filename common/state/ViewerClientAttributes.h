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

#ifndef VIEWERCLIENTATTRIBUTES_H
#define VIEWERCLIENTATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>


// ****************************************************************************
// Class: ViewerClientAttributes
//
// Purpose:
//    This class contains attributes used for viewer client
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API ViewerClientAttributes : public AttributeSubject
{
public:
    enum RenderType
    {
        None,
        Image,
        Data
    };

    // These constructors are for objects of this class
    ViewerClientAttributes();
    ViewerClientAttributes(const ViewerClientAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    ViewerClientAttributes(private_tmfs_t tmfs);
    ViewerClientAttributes(const ViewerClientAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~ViewerClientAttributes();

    virtual ViewerClientAttributes& operator = (const ViewerClientAttributes &obj);
    virtual bool operator == (const ViewerClientAttributes &obj) const;
    virtual bool operator != (const ViewerClientAttributes &obj) const;
private:
    void Init();
    void Copy(const ViewerClientAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectTitle();
    void SelectWindowIds();

    // Property setting methods
    void SetRenderingType(RenderType renderingType_);
    void SetId(int id_);
    void SetTitle(const std::string &title_);
    void SetWindowIds(const intVector &windowIds_);
    void SetImageWidth(int imageWidth_);
    void SetImageHeight(int imageHeight_);
    void SetImageResolutionPcnt(double imageResolutionPcnt_);
    void SetExternalClient(bool externalClient_);

    // Property getting methods
    RenderType        GetRenderingType() const;
    int               GetId() const;
    const std::string &GetTitle() const;
          std::string &GetTitle();
    const intVector   &GetWindowIds() const;
          intVector   &GetWindowIds();
    int               GetImageWidth() const;
    int               GetImageHeight() const;
    double            GetImageResolutionPcnt() const;
    bool              GetExternalClient() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string RenderType_ToString(RenderType);
    static bool RenderType_FromString(const std::string &, RenderType &);
protected:
    static std::string RenderType_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_renderingType = 0,
        ID_id,
        ID_title,
        ID_windowIds,
        ID_imageWidth,
        ID_imageHeight,
        ID_imageResolutionPcnt,
        ID_externalClient,
        ID__LAST
    };

private:
    int         renderingType;
    int         id;
    std::string title;
    intVector   windowIds;
    int         imageWidth;
    int         imageHeight;
    double      imageResolutionPcnt;
    bool        externalClient;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define VIEWERCLIENTATTRIBUTES_TMFS "iisi*iidb"

#endif
