/*****************************************************************************
*
* Copyright (c) 2000 - 2007, The Regents of the University of California
* Produced at the Lawrence Livermore National Laboratory
* All rights reserved.
*
* This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
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
*    documentation and/or materials provided with the distribution.
*  - Neither the name of the UC/LLNL nor  the names of its contributors may be
*    used to  endorse or  promote products derived from  this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
* CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
* ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef LINE_H
#define LINE_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>
#include <ColorAttribute.h>

// ****************************************************************************
// Class: Line
//
// Purpose:
//    Attributes for a line
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Tue Jul 27 09:34:37 PDT 2004
//
// Modifications:
//   
// ****************************************************************************

class STATE_API Line : public AttributeSubject
{
public:
    Line();
    Line(const Line &obj);
    virtual ~Line();

    virtual void operator = (const Line &obj);
    virtual bool operator == (const Line &obj) const;
    virtual bool operator != (const Line &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectPoint1();
    void SelectPoint2();
    void SelectDesignator();
    void SelectColor();
    void SelectVarName();

    // Property setting methods
    void SetPoint1(const double *point1_);
    void SetPoint2(const double *point2_);
    void SetDesignator(const std::string &designator_);
    void SetColor(const ColorAttribute &color_);
    void SetLineStyle(int lineStyle_);
    void SetLineWidth(int lineWidth_);
    void SetInteractive(bool interactive_);
    void SetReflineLabels(bool reflineLabels_);
    void SetVarName(const std::string &varName_);
    void SetSamplingOn(bool samplingOn_);
    void SetNumSamples(int numSamples_);

    // Property getting methods
    const double         *GetPoint1() const;
          double         *GetPoint1();
    const double         *GetPoint2() const;
          double         *GetPoint2();
    const std::string    &GetDesignator() const;
          std::string    &GetDesignator();
    const ColorAttribute &GetColor() const;
          ColorAttribute &GetColor();
    int                  GetLineStyle() const;
    int                  GetLineWidth() const;
    bool                 GetInteractive() const;
    bool                 GetReflineLabels() const;
    const std::string    &GetVarName() const;
          std::string    &GetVarName();
    bool                 GetSamplingOn() const;
    int                  GetNumSamples() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    void SetPoint1(double,double,double);
    void SetPoint2(double,double,double);
private:
    double         point1[3];
    double         point2[3];
    std::string    designator;
    ColorAttribute color;
    int            lineStyle;
    int            lineWidth;
    bool           interactive;
    bool           reflineLabels;
    std::string    varName;
    bool           samplingOn;
    int            numSamples;
};

#endif
