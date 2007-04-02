// ****************************************************************************
//
// Copyright (c) 2000 - 2007, The Regents of the University of California
// Produced at the Lawrence Livermore National Laboratory
// All rights reserved.
//
// This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
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
//    documentation and/or materials provided with the distribution.
//  - Neither the name of the UC/LLNL nor  the names of its contributors may be
//    used to  endorse or  promote products derived from  this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
// ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
// CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
// ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
// SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
// CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
// LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
// OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ****************************************************************************

package llnl.visit;


// ****************************************************************************
// Class: ViewCurveAttributes
//
// Purpose:
//    This class contains the curve view attributes.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Wed Aug 27 08:55:15 PDT 2003
//
// Modifications:
//   
// ****************************************************************************

public class ViewCurveAttributes extends AttributeSubject
{
    public ViewCurveAttributes()
    {
        super(3);

        domainCoords = new double[2];
        domainCoords[0] = 0;
        domainCoords[1] = 1;
        rangeCoords = new double[2];
        rangeCoords[0] = 0;
        rangeCoords[1] = 1;
        viewportCoords = new double[4];
        viewportCoords[0] = 0.1;
        viewportCoords[1] = 0.1;
        viewportCoords[2] = 0.9;
        viewportCoords[3] = 0.9;
    }

    public ViewCurveAttributes(ViewCurveAttributes obj)
    {
        super(3);

        int i;

        domainCoords = new double[2];
        domainCoords[0] = obj.domainCoords[0];
        domainCoords[1] = obj.domainCoords[1];

        rangeCoords = new double[2];
        rangeCoords[0] = obj.rangeCoords[0];
        rangeCoords[1] = obj.rangeCoords[1];

        viewportCoords = new double[4];
        for(i = 0; i < obj.viewportCoords.length; ++i)
            viewportCoords[i] = obj.viewportCoords[i];


        SelectAll();
    }

    public boolean equals(ViewCurveAttributes obj)
    {
        int i;

        // Compare the domainCoords arrays.
        boolean domainCoords_equal = true;
        for(i = 0; i < 2 && domainCoords_equal; ++i)
            domainCoords_equal = (domainCoords[i] == obj.domainCoords[i]);

        // Compare the rangeCoords arrays.
        boolean rangeCoords_equal = true;
        for(i = 0; i < 2 && rangeCoords_equal; ++i)
            rangeCoords_equal = (rangeCoords[i] == obj.rangeCoords[i]);

        // Compare the viewportCoords arrays.
        boolean viewportCoords_equal = true;
        for(i = 0; i < 4 && viewportCoords_equal; ++i)
            viewportCoords_equal = (viewportCoords[i] == obj.viewportCoords[i]);

        // Create the return value
        return (domainCoords_equal &&
                rangeCoords_equal &&
                viewportCoords_equal);
    }

    // Property setting methods
    public void SetDomainCoords(double[] domainCoords_)
    {
        domainCoords[0] = domainCoords_[0];
        domainCoords[1] = domainCoords_[1];
        Select(0);
    }

    public void SetDomainCoords(double e0, double e1)
    {
        domainCoords[0] = e0;
        domainCoords[1] = e1;
        Select(0);
    }

    public void SetRangeCoords(double[] rangeCoords_)
    {
        rangeCoords[0] = rangeCoords_[0];
        rangeCoords[1] = rangeCoords_[1];
        Select(1);
    }

    public void SetRangeCoords(double e0, double e1)
    {
        rangeCoords[0] = e0;
        rangeCoords[1] = e1;
        Select(1);
    }

    public void SetViewportCoords(double[] viewportCoords_)
    {
        viewportCoords[0] = viewportCoords_[0];
        viewportCoords[1] = viewportCoords_[1];
        viewportCoords[2] = viewportCoords_[2];
        viewportCoords[3] = viewportCoords_[3];
        Select(2);
    }

    public void SetViewportCoords(double e0, double e1, double e2, double e3)
    {
        viewportCoords[0] = e0;
        viewportCoords[1] = e1;
        viewportCoords[2] = e2;
        viewportCoords[3] = e3;
        Select(2);
    }

    // Property getting methods
    public double[] GetDomainCoords() { return domainCoords; }
    public double[] GetRangeCoords() { return rangeCoords; }
    public double[] GetViewportCoords() { return viewportCoords; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteDoubleArray(domainCoords);
        if(WriteSelect(1, buf))
            buf.WriteDoubleArray(rangeCoords);
        if(WriteSelect(2, buf))
            buf.WriteDoubleArray(viewportCoords);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetDomainCoords(buf.ReadDoubleArray());
                break;
            case 1:
                SetRangeCoords(buf.ReadDoubleArray());
                break;
            case 2:
                SetViewportCoords(buf.ReadDoubleArray());
                break;
            }
        }
    }


    // Attributes
    private double[] domainCoords;
    private double[] rangeCoords;
    private double[] viewportCoords;
}

