// ***************************************************************************
//
// Copyright (c) 2000 - 2008, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory
// LLNL-CODE-400142
// All rights reserved.
//
// This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
// full copyright notice is contained in the file COPYRIGHT located at the root
// of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
//
// Redistribution  and  use  in  source  and  binary  forms,  with  or  without
// modification, are permitted provided that the following conditions are met:
//
//  - Redistributions of  source code must  retain the above  copyright notice,
//    this list of conditions and the disclaimer below.
//  - Redistributions in binary form must reproduce the above copyright notice,
//    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
//    documentation and/or other materials provided with the distribution.
//  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
//    be used to endorse or promote products derived from this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
// ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
// LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
// DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
// SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
// CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
// LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
// OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ***************************************************************************

package llnl.visit.plots;

import llnl.visit.AttributeSubject;
import llnl.visit.CommunicationBuffer;
import llnl.visit.Plugin;
import llnl.visit.ColorAttribute;

// ****************************************************************************
// Class: PoincareAttributes
//
// Purpose:
//    Attributes for the Poincare plot
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class PoincareAttributes extends AttributeSubject implements Plugin
{
    // Enum values
    public final static int SOURCETYPE_SPECIFIEDPOINT = 0;
    public final static int SOURCETYPE_SPECIFIEDLINE = 1;
    public final static int SOURCETYPE_SPECIFIEDPLANE = 2;

    public final static int TERMINATIONTYPE_DISTANCE = 0;
    public final static int TERMINATIONTYPE_TIME = 1;
    public final static int TERMINATIONTYPE_STEP = 2;

    public final static int COLORSTYLETYPE_ORIGINALVALUE = 0;
    public final static int COLORSTYLETYPE_INPUTORDER = 1;
    public final static int COLORSTYLETYPE_POINTINDEX = 2;
    public final static int COLORSTYLETYPE_PLANE = 3;
    public final static int COLORSTYLETYPE_TOROIDALWINDINGORDER = 4;
    public final static int COLORSTYLETYPE_TOROIDALWINDINGPOINTORDER = 5;
    public final static int COLORSTYLETYPE_TOROIDALWINDINGS = 6;
    public final static int COLORSTYLETYPE_POLOIDALWINDINGS = 7;
    public final static int COLORSTYLETYPE_SAFETYFACTOR = 8;

    public final static int SHOWMESHTYPE_CURVES = 0;
    public final static int SHOWMESHTYPE_SURFACES = 1;

    public final static int OVERLAPTYPE_RAW = 0;
    public final static int OVERLAPTYPE_REMOVE = 1;
    public final static int OVERLAPTYPE_MERGE = 2;
    public final static int OVERLAPTYPE_SMOOTH = 3;

    public final static int INTEGRATIONTYPE_DORMANDPRINCE = 0;
    public final static int INTEGRATIONTYPE_ADAMSBASHFORTH = 1;


    public PoincareAttributes()
    {
        super(30);

        sourceType = SOURCETYPE_SPECIFIEDPOINT;
        maxStepLength = 0.1;
        termination = 10;
        pointSource = new double[3];
        pointSource[0] = 0;
        pointSource[1] = 0;
        pointSource[2] = 0;
        lineStart = new double[3];
        lineStart[0] = 0;
        lineStart[1] = 0;
        lineStart[2] = 0;
        lineEnd = new double[3];
        lineEnd[0] = 1;
        lineEnd[1] = 0;
        lineEnd[2] = 0;
        planeOrigin = new double[3];
        planeOrigin[0] = 0;
        planeOrigin[1] = 0;
        planeOrigin[2] = 0;
        planeNormal = new double[3];
        planeNormal[0] = 0;
        planeNormal[1] = 0;
        planeNormal[2] = 1;
        planeUpAxis = new double[3];
        planeUpAxis[0] = 0;
        planeUpAxis[1] = 1;
        planeUpAxis[2] = 0;
        legendFlag = true;
        lightingFlag = true;
        relTol = 0.0001;
        absTol = 1e-05;
        terminationType = TERMINATIONTYPE_STEP;
        integrationType = INTEGRATIONTYPE_ADAMSBASHFORTH;
        showStreamlines = false;
        showPoints = false;
        pointDensity = 1;
        sourceRadius = 1;
        colorTableName = new String("Default");
        singleColor = new ColorAttribute(0, 0, 0);
        NumberPlanes = 1;
        ColorStyle = COLORSTYLETYPE_SAFETYFACTOR;
        MaxToroidalWinding = 30;
        OverrideToroidalWinding = 0;
        HitRate = 0.9;
        ShowCurves = SHOWMESHTYPE_CURVES;
        AdjustPlane = -1;
        ShowIslands = false;
        Overlaps = OVERLAPTYPE_REMOVE;
    }

    public PoincareAttributes(PoincareAttributes obj)
    {
        super(30);

        int i;

        sourceType = obj.sourceType;
        maxStepLength = obj.maxStepLength;
        termination = obj.termination;
        pointSource = new double[3];
        pointSource[0] = obj.pointSource[0];
        pointSource[1] = obj.pointSource[1];
        pointSource[2] = obj.pointSource[2];

        lineStart = new double[3];
        lineStart[0] = obj.lineStart[0];
        lineStart[1] = obj.lineStart[1];
        lineStart[2] = obj.lineStart[2];

        lineEnd = new double[3];
        lineEnd[0] = obj.lineEnd[0];
        lineEnd[1] = obj.lineEnd[1];
        lineEnd[2] = obj.lineEnd[2];

        planeOrigin = new double[3];
        planeOrigin[0] = obj.planeOrigin[0];
        planeOrigin[1] = obj.planeOrigin[1];
        planeOrigin[2] = obj.planeOrigin[2];

        planeNormal = new double[3];
        planeNormal[0] = obj.planeNormal[0];
        planeNormal[1] = obj.planeNormal[1];
        planeNormal[2] = obj.planeNormal[2];

        planeUpAxis = new double[3];
        planeUpAxis[0] = obj.planeUpAxis[0];
        planeUpAxis[1] = obj.planeUpAxis[1];
        planeUpAxis[2] = obj.planeUpAxis[2];

        legendFlag = obj.legendFlag;
        lightingFlag = obj.lightingFlag;
        relTol = obj.relTol;
        absTol = obj.absTol;
        terminationType = obj.terminationType;
        integrationType = obj.integrationType;
        showStreamlines = obj.showStreamlines;
        showPoints = obj.showPoints;
        pointDensity = obj.pointDensity;
        sourceRadius = obj.sourceRadius;
        colorTableName = new String(obj.colorTableName);
        singleColor = new ColorAttribute(obj.singleColor);
        NumberPlanes = obj.NumberPlanes;
        ColorStyle = obj.ColorStyle;
        MaxToroidalWinding = obj.MaxToroidalWinding;
        OverrideToroidalWinding = obj.OverrideToroidalWinding;
        HitRate = obj.HitRate;
        ShowCurves = obj.ShowCurves;
        AdjustPlane = obj.AdjustPlane;
        ShowIslands = obj.ShowIslands;
        Overlaps = obj.Overlaps;

        SelectAll();
    }

    public boolean equals(PoincareAttributes obj)
    {
        int i;

        // Compare the pointSource arrays.
        boolean pointSource_equal = true;
        for(i = 0; i < 3 && pointSource_equal; ++i)
            pointSource_equal = (pointSource[i] == obj.pointSource[i]);

        // Compare the lineStart arrays.
        boolean lineStart_equal = true;
        for(i = 0; i < 3 && lineStart_equal; ++i)
            lineStart_equal = (lineStart[i] == obj.lineStart[i]);

        // Compare the lineEnd arrays.
        boolean lineEnd_equal = true;
        for(i = 0; i < 3 && lineEnd_equal; ++i)
            lineEnd_equal = (lineEnd[i] == obj.lineEnd[i]);

        // Compare the planeOrigin arrays.
        boolean planeOrigin_equal = true;
        for(i = 0; i < 3 && planeOrigin_equal; ++i)
            planeOrigin_equal = (planeOrigin[i] == obj.planeOrigin[i]);

        // Compare the planeNormal arrays.
        boolean planeNormal_equal = true;
        for(i = 0; i < 3 && planeNormal_equal; ++i)
            planeNormal_equal = (planeNormal[i] == obj.planeNormal[i]);

        // Compare the planeUpAxis arrays.
        boolean planeUpAxis_equal = true;
        for(i = 0; i < 3 && planeUpAxis_equal; ++i)
            planeUpAxis_equal = (planeUpAxis[i] == obj.planeUpAxis[i]);

        // Create the return value
        return ((sourceType == obj.sourceType) &&
                (maxStepLength == obj.maxStepLength) &&
                (termination == obj.termination) &&
                pointSource_equal &&
                lineStart_equal &&
                lineEnd_equal &&
                planeOrigin_equal &&
                planeNormal_equal &&
                planeUpAxis_equal &&
                (legendFlag == obj.legendFlag) &&
                (lightingFlag == obj.lightingFlag) &&
                (relTol == obj.relTol) &&
                (absTol == obj.absTol) &&
                (terminationType == obj.terminationType) &&
                (integrationType == obj.integrationType) &&
                (showStreamlines == obj.showStreamlines) &&
                (showPoints == obj.showPoints) &&
                (pointDensity == obj.pointDensity) &&
                (sourceRadius == obj.sourceRadius) &&
                (colorTableName.equals(obj.colorTableName)) &&
                (singleColor == obj.singleColor) &&
                (NumberPlanes == obj.NumberPlanes) &&
                (ColorStyle == obj.ColorStyle) &&
                (MaxToroidalWinding == obj.MaxToroidalWinding) &&
                (OverrideToroidalWinding == obj.OverrideToroidalWinding) &&
                (HitRate == obj.HitRate) &&
                (ShowCurves == obj.ShowCurves) &&
                (AdjustPlane == obj.AdjustPlane) &&
                (ShowIslands == obj.ShowIslands) &&
                (Overlaps == obj.Overlaps));
    }

    public String GetName() { return "Poincare"; }
    public String GetVersion() { return "1.0"; }

    // Property setting methods
    public void SetSourceType(int sourceType_)
    {
        sourceType = sourceType_;
        Select(0);
    }

    public void SetMaxStepLength(double maxStepLength_)
    {
        maxStepLength = maxStepLength_;
        Select(1);
    }

    public void SetTermination(double termination_)
    {
        termination = termination_;
        Select(2);
    }

    public void SetPointSource(double[] pointSource_)
    {
        pointSource[0] = pointSource_[0];
        pointSource[1] = pointSource_[1];
        pointSource[2] = pointSource_[2];
        Select(3);
    }

    public void SetPointSource(double e0, double e1, double e2)
    {
        pointSource[0] = e0;
        pointSource[1] = e1;
        pointSource[2] = e2;
        Select(3);
    }

    public void SetLineStart(double[] lineStart_)
    {
        lineStart[0] = lineStart_[0];
        lineStart[1] = lineStart_[1];
        lineStart[2] = lineStart_[2];
        Select(4);
    }

    public void SetLineStart(double e0, double e1, double e2)
    {
        lineStart[0] = e0;
        lineStart[1] = e1;
        lineStart[2] = e2;
        Select(4);
    }

    public void SetLineEnd(double[] lineEnd_)
    {
        lineEnd[0] = lineEnd_[0];
        lineEnd[1] = lineEnd_[1];
        lineEnd[2] = lineEnd_[2];
        Select(5);
    }

    public void SetLineEnd(double e0, double e1, double e2)
    {
        lineEnd[0] = e0;
        lineEnd[1] = e1;
        lineEnd[2] = e2;
        Select(5);
    }

    public void SetPlaneOrigin(double[] planeOrigin_)
    {
        planeOrigin[0] = planeOrigin_[0];
        planeOrigin[1] = planeOrigin_[1];
        planeOrigin[2] = planeOrigin_[2];
        Select(6);
    }

    public void SetPlaneOrigin(double e0, double e1, double e2)
    {
        planeOrigin[0] = e0;
        planeOrigin[1] = e1;
        planeOrigin[2] = e2;
        Select(6);
    }

    public void SetPlaneNormal(double[] planeNormal_)
    {
        planeNormal[0] = planeNormal_[0];
        planeNormal[1] = planeNormal_[1];
        planeNormal[2] = planeNormal_[2];
        Select(7);
    }

    public void SetPlaneNormal(double e0, double e1, double e2)
    {
        planeNormal[0] = e0;
        planeNormal[1] = e1;
        planeNormal[2] = e2;
        Select(7);
    }

    public void SetPlaneUpAxis(double[] planeUpAxis_)
    {
        planeUpAxis[0] = planeUpAxis_[0];
        planeUpAxis[1] = planeUpAxis_[1];
        planeUpAxis[2] = planeUpAxis_[2];
        Select(8);
    }

    public void SetPlaneUpAxis(double e0, double e1, double e2)
    {
        planeUpAxis[0] = e0;
        planeUpAxis[1] = e1;
        planeUpAxis[2] = e2;
        Select(8);
    }

    public void SetLegendFlag(boolean legendFlag_)
    {
        legendFlag = legendFlag_;
        Select(9);
    }

    public void SetLightingFlag(boolean lightingFlag_)
    {
        lightingFlag = lightingFlag_;
        Select(10);
    }

    public void SetRelTol(double relTol_)
    {
        relTol = relTol_;
        Select(11);
    }

    public void SetAbsTol(double absTol_)
    {
        absTol = absTol_;
        Select(12);
    }

    public void SetTerminationType(int terminationType_)
    {
        terminationType = terminationType_;
        Select(13);
    }

    public void SetIntegrationType(int integrationType_)
    {
        integrationType = integrationType_;
        Select(14);
    }

    public void SetShowStreamlines(boolean showStreamlines_)
    {
        showStreamlines = showStreamlines_;
        Select(15);
    }

    public void SetShowPoints(boolean showPoints_)
    {
        showPoints = showPoints_;
        Select(16);
    }

    public void SetPointDensity(int pointDensity_)
    {
        pointDensity = pointDensity_;
        Select(17);
    }

    public void SetSourceRadius(double sourceRadius_)
    {
        sourceRadius = sourceRadius_;
        Select(18);
    }

    public void SetColorTableName(String colorTableName_)
    {
        colorTableName = colorTableName_;
        Select(19);
    }

    public void SetSingleColor(ColorAttribute singleColor_)
    {
        singleColor = singleColor_;
        Select(20);
    }

    public void SetNumberPlanes(int NumberPlanes_)
    {
        NumberPlanes = NumberPlanes_;
        Select(21);
    }

    public void SetColorStyle(int ColorStyle_)
    {
        ColorStyle = ColorStyle_;
        Select(22);
    }

    public void SetMaxToroidalWinding(int MaxToroidalWinding_)
    {
        MaxToroidalWinding = MaxToroidalWinding_;
        Select(23);
    }

    public void SetOverrideToroidalWinding(int OverrideToroidalWinding_)
    {
        OverrideToroidalWinding = OverrideToroidalWinding_;
        Select(24);
    }

    public void SetHitRate(double HitRate_)
    {
        HitRate = HitRate_;
        Select(25);
    }

    public void SetShowCurves(int ShowCurves_)
    {
        ShowCurves = ShowCurves_;
        Select(26);
    }

    public void SetAdjustPlane(int AdjustPlane_)
    {
        AdjustPlane = AdjustPlane_;
        Select(27);
    }

    public void SetShowIslands(boolean ShowIslands_)
    {
        ShowIslands = ShowIslands_;
        Select(28);
    }

    public void SetOverlaps(int Overlaps_)
    {
        Overlaps = Overlaps_;
        Select(29);
    }

    // Property getting methods
    public int            GetSourceType() { return sourceType; }
    public double         GetMaxStepLength() { return maxStepLength; }
    public double         GetTermination() { return termination; }
    public double[]       GetPointSource() { return pointSource; }
    public double[]       GetLineStart() { return lineStart; }
    public double[]       GetLineEnd() { return lineEnd; }
    public double[]       GetPlaneOrigin() { return planeOrigin; }
    public double[]       GetPlaneNormal() { return planeNormal; }
    public double[]       GetPlaneUpAxis() { return planeUpAxis; }
    public boolean        GetLegendFlag() { return legendFlag; }
    public boolean        GetLightingFlag() { return lightingFlag; }
    public double         GetRelTol() { return relTol; }
    public double         GetAbsTol() { return absTol; }
    public int            GetTerminationType() { return terminationType; }
    public int            GetIntegrationType() { return integrationType; }
    public boolean        GetShowStreamlines() { return showStreamlines; }
    public boolean        GetShowPoints() { return showPoints; }
    public int            GetPointDensity() { return pointDensity; }
    public double         GetSourceRadius() { return sourceRadius; }
    public String         GetColorTableName() { return colorTableName; }
    public ColorAttribute GetSingleColor() { return singleColor; }
    public int            GetNumberPlanes() { return NumberPlanes; }
    public int            GetColorStyle() { return ColorStyle; }
    public int            GetMaxToroidalWinding() { return MaxToroidalWinding; }
    public int            GetOverrideToroidalWinding() { return OverrideToroidalWinding; }
    public double         GetHitRate() { return HitRate; }
    public int            GetShowCurves() { return ShowCurves; }
    public int            GetAdjustPlane() { return AdjustPlane; }
    public boolean        GetShowIslands() { return ShowIslands; }
    public int            GetOverlaps() { return Overlaps; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteInt(sourceType);
        if(WriteSelect(1, buf))
            buf.WriteDouble(maxStepLength);
        if(WriteSelect(2, buf))
            buf.WriteDouble(termination);
        if(WriteSelect(3, buf))
            buf.WriteDoubleArray(pointSource);
        if(WriteSelect(4, buf))
            buf.WriteDoubleArray(lineStart);
        if(WriteSelect(5, buf))
            buf.WriteDoubleArray(lineEnd);
        if(WriteSelect(6, buf))
            buf.WriteDoubleArray(planeOrigin);
        if(WriteSelect(7, buf))
            buf.WriteDoubleArray(planeNormal);
        if(WriteSelect(8, buf))
            buf.WriteDoubleArray(planeUpAxis);
        if(WriteSelect(9, buf))
            buf.WriteBool(legendFlag);
        if(WriteSelect(10, buf))
            buf.WriteBool(lightingFlag);
        if(WriteSelect(11, buf))
            buf.WriteDouble(relTol);
        if(WriteSelect(12, buf))
            buf.WriteDouble(absTol);
        if(WriteSelect(13, buf))
            buf.WriteInt(terminationType);
        if(WriteSelect(14, buf))
            buf.WriteInt(integrationType);
        if(WriteSelect(15, buf))
            buf.WriteBool(showStreamlines);
        if(WriteSelect(16, buf))
            buf.WriteBool(showPoints);
        if(WriteSelect(17, buf))
            buf.WriteInt(pointDensity);
        if(WriteSelect(18, buf))
            buf.WriteDouble(sourceRadius);
        if(WriteSelect(19, buf))
            buf.WriteString(colorTableName);
        if(WriteSelect(20, buf))
            singleColor.Write(buf);
        if(WriteSelect(21, buf))
            buf.WriteInt(NumberPlanes);
        if(WriteSelect(22, buf))
            buf.WriteInt(ColorStyle);
        if(WriteSelect(23, buf))
            buf.WriteInt(MaxToroidalWinding);
        if(WriteSelect(24, buf))
            buf.WriteInt(OverrideToroidalWinding);
        if(WriteSelect(25, buf))
            buf.WriteDouble(HitRate);
        if(WriteSelect(26, buf))
            buf.WriteInt(ShowCurves);
        if(WriteSelect(27, buf))
            buf.WriteInt(AdjustPlane);
        if(WriteSelect(28, buf))
            buf.WriteBool(ShowIslands);
        if(WriteSelect(29, buf))
            buf.WriteInt(Overlaps);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetSourceType(buf.ReadInt());
                break;
            case 1:
                SetMaxStepLength(buf.ReadDouble());
                break;
            case 2:
                SetTermination(buf.ReadDouble());
                break;
            case 3:
                SetPointSource(buf.ReadDoubleArray());
                break;
            case 4:
                SetLineStart(buf.ReadDoubleArray());
                break;
            case 5:
                SetLineEnd(buf.ReadDoubleArray());
                break;
            case 6:
                SetPlaneOrigin(buf.ReadDoubleArray());
                break;
            case 7:
                SetPlaneNormal(buf.ReadDoubleArray());
                break;
            case 8:
                SetPlaneUpAxis(buf.ReadDoubleArray());
                break;
            case 9:
                SetLegendFlag(buf.ReadBool());
                break;
            case 10:
                SetLightingFlag(buf.ReadBool());
                break;
            case 11:
                SetRelTol(buf.ReadDouble());
                break;
            case 12:
                SetAbsTol(buf.ReadDouble());
                break;
            case 13:
                SetTerminationType(buf.ReadInt());
                break;
            case 14:
                SetIntegrationType(buf.ReadInt());
                break;
            case 15:
                SetShowStreamlines(buf.ReadBool());
                break;
            case 16:
                SetShowPoints(buf.ReadBool());
                break;
            case 17:
                SetPointDensity(buf.ReadInt());
                break;
            case 18:
                SetSourceRadius(buf.ReadDouble());
                break;
            case 19:
                SetColorTableName(buf.ReadString());
                break;
            case 20:
                singleColor.Read(buf);
                Select(20);
                break;
            case 21:
                SetNumberPlanes(buf.ReadInt());
                break;
            case 22:
                SetColorStyle(buf.ReadInt());
                break;
            case 23:
                SetMaxToroidalWinding(buf.ReadInt());
                break;
            case 24:
                SetOverrideToroidalWinding(buf.ReadInt());
                break;
            case 25:
                SetHitRate(buf.ReadDouble());
                break;
            case 26:
                SetShowCurves(buf.ReadInt());
                break;
            case 27:
                SetAdjustPlane(buf.ReadInt());
                break;
            case 28:
                SetShowIslands(buf.ReadBool());
                break;
            case 29:
                SetOverlaps(buf.ReadInt());
                break;
            }
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + indent + "sourceType = ";
        if(sourceType == SOURCETYPE_SPECIFIEDPOINT)
            str = str + "SOURCETYPE_SPECIFIEDPOINT";
        if(sourceType == SOURCETYPE_SPECIFIEDLINE)
            str = str + "SOURCETYPE_SPECIFIEDLINE";
        if(sourceType == SOURCETYPE_SPECIFIEDPLANE)
            str = str + "SOURCETYPE_SPECIFIEDPLANE";
        str = str + "\n";
        str = str + doubleToString("maxStepLength", maxStepLength, indent) + "\n";
        str = str + doubleToString("termination", termination, indent) + "\n";
        str = str + doubleArrayToString("pointSource", pointSource, indent) + "\n";
        str = str + doubleArrayToString("lineStart", lineStart, indent) + "\n";
        str = str + doubleArrayToString("lineEnd", lineEnd, indent) + "\n";
        str = str + doubleArrayToString("planeOrigin", planeOrigin, indent) + "\n";
        str = str + doubleArrayToString("planeNormal", planeNormal, indent) + "\n";
        str = str + doubleArrayToString("planeUpAxis", planeUpAxis, indent) + "\n";
        str = str + boolToString("legendFlag", legendFlag, indent) + "\n";
        str = str + boolToString("lightingFlag", lightingFlag, indent) + "\n";
        str = str + doubleToString("relTol", relTol, indent) + "\n";
        str = str + doubleToString("absTol", absTol, indent) + "\n";
        str = str + indent + "terminationType = ";
        if(terminationType == TERMINATIONTYPE_DISTANCE)
            str = str + "TERMINATIONTYPE_DISTANCE";
        if(terminationType == TERMINATIONTYPE_TIME)
            str = str + "TERMINATIONTYPE_TIME";
        if(terminationType == TERMINATIONTYPE_STEP)
            str = str + "TERMINATIONTYPE_STEP";
        str = str + "\n";
        str = str + indent + "integrationType = ";
        if(integrationType == INTEGRATIONTYPE_DORMANDPRINCE)
            str = str + "INTEGRATIONTYPE_DORMANDPRINCE";
        if(integrationType == INTEGRATIONTYPE_ADAMSBASHFORTH)
            str = str + "INTEGRATIONTYPE_ADAMSBASHFORTH";
        str = str + "\n";
        str = str + boolToString("showStreamlines", showStreamlines, indent) + "\n";
        str = str + boolToString("showPoints", showPoints, indent) + "\n";
        str = str + intToString("pointDensity", pointDensity, indent) + "\n";
        str = str + doubleToString("sourceRadius", sourceRadius, indent) + "\n";
        str = str + stringToString("colorTableName", colorTableName, indent) + "\n";
        str = str + indent + "singleColor = {" + singleColor.Red() + ", " + singleColor.Green() + ", " + singleColor.Blue() + ", " + singleColor.Alpha() + "}\n";
        str = str + intToString("NumberPlanes", NumberPlanes, indent) + "\n";
        str = str + indent + "ColorStyle = ";
        if(ColorStyle == COLORSTYLETYPE_ORIGINALVALUE)
            str = str + "COLORSTYLETYPE_ORIGINALVALUE";
        if(ColorStyle == COLORSTYLETYPE_INPUTORDER)
            str = str + "COLORSTYLETYPE_INPUTORDER";
        if(ColorStyle == COLORSTYLETYPE_POINTINDEX)
            str = str + "COLORSTYLETYPE_POINTINDEX";
        if(ColorStyle == COLORSTYLETYPE_PLANE)
            str = str + "COLORSTYLETYPE_PLANE";
        if(ColorStyle == COLORSTYLETYPE_TOROIDALWINDINGORDER)
            str = str + "COLORSTYLETYPE_TOROIDALWINDINGORDER";
        if(ColorStyle == COLORSTYLETYPE_TOROIDALWINDINGPOINTORDER)
            str = str + "COLORSTYLETYPE_TOROIDALWINDINGPOINTORDER";
        if(ColorStyle == COLORSTYLETYPE_TOROIDALWINDINGS)
            str = str + "COLORSTYLETYPE_TOROIDALWINDINGS";
        if(ColorStyle == COLORSTYLETYPE_POLOIDALWINDINGS)
            str = str + "COLORSTYLETYPE_POLOIDALWINDINGS";
        if(ColorStyle == COLORSTYLETYPE_SAFETYFACTOR)
            str = str + "COLORSTYLETYPE_SAFETYFACTOR";
        str = str + "\n";
        str = str + intToString("MaxToroidalWinding", MaxToroidalWinding, indent) + "\n";
        str = str + intToString("OverrideToroidalWinding", OverrideToroidalWinding, indent) + "\n";
        str = str + doubleToString("HitRate", HitRate, indent) + "\n";
        str = str + indent + "ShowCurves = ";
        if(ShowCurves == SHOWMESHTYPE_CURVES)
            str = str + "SHOWMESHTYPE_CURVES";
        if(ShowCurves == SHOWMESHTYPE_SURFACES)
            str = str + "SHOWMESHTYPE_SURFACES";
        str = str + "\n";
        str = str + intToString("AdjustPlane", AdjustPlane, indent) + "\n";
        str = str + boolToString("ShowIslands", ShowIslands, indent) + "\n";
        str = str + indent + "Overlaps = ";
        if(Overlaps == OVERLAPTYPE_RAW)
            str = str + "OVERLAPTYPE_RAW";
        if(Overlaps == OVERLAPTYPE_REMOVE)
            str = str + "OVERLAPTYPE_REMOVE";
        if(Overlaps == OVERLAPTYPE_MERGE)
            str = str + "OVERLAPTYPE_MERGE";
        if(Overlaps == OVERLAPTYPE_SMOOTH)
            str = str + "OVERLAPTYPE_SMOOTH";
        str = str + "\n";
        return str;
    }


    // Attributes
    private int            sourceType;
    private double         maxStepLength;
    private double         termination;
    private double[]       pointSource;
    private double[]       lineStart;
    private double[]       lineEnd;
    private double[]       planeOrigin;
    private double[]       planeNormal;
    private double[]       planeUpAxis;
    private boolean        legendFlag;
    private boolean        lightingFlag;
    private double         relTol;
    private double         absTol;
    private int            terminationType;
    private int            integrationType;
    private boolean        showStreamlines;
    private boolean        showPoints;
    private int            pointDensity;
    private double         sourceRadius;
    private String         colorTableName;
    private ColorAttribute singleColor;
    private int            NumberPlanes;
    private int            ColorStyle;
    private int            MaxToroidalWinding;
    private int            OverrideToroidalWinding;
    private double         HitRate;
    private int            ShowCurves;
    private int            AdjustPlane;
    private boolean        ShowIslands;
    private int            Overlaps;
}

