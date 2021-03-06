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

// ************************************************************************* //
//                       avtStrainGreenLagrangeExpression.C                  //
// ************************************************************************* //

#include <avtStrainGreenLagrangeExpression.h>
#include <math.h>

#include <vtkCellType.h>
#include <vtkDataArray.h>
#include <vtkDataSet.h>
#include <vtkIdList.h>
#include <vtkPointData.h>
#include <vtkUnstructuredGrid.h>

#include <ExpressionException.h>

#include <vector>

// ****************************************************************************
//  Method: avtStrainGreenLagrangeExpression constructor
//
//  Programmer: Thomas R. Treadway
//  Creation:   Tue Nov 14 17:31:42 PST 2006
//
// ****************************************************************************

avtStrainGreenLagrangeExpression::avtStrainGreenLagrangeExpression()
{
    ;
}

// ****************************************************************************
//  Method: avtStrainGreenLagrangeExpression destructor
//
//  Programmer: Thomas R. Treadway
//  Creation:   Tue Nov 14 17:31:42 PST 2006
//
// ****************************************************************************

avtStrainGreenLagrangeExpression::~avtStrainGreenLagrangeExpression()
{
    ;
}

// ****************************************************************************
//  Method: avtStrainGreenLagrangeExpression::DeriveVariable
//
//  Purpose:
//      Determines the strain using Green Lagrange
//
//  Programmer: Thomas R. Treadway
//  Creation:   Tue Nov 14 17:31:42 PST 2006
//
//  Modifications:
//    Kathleen Biagas, Wed Apr 4 12:02:10 PDT 2012
//    Set output's data type to same as input.
//
// ****************************************************************************

vtkDataArray *
avtStrainGreenLagrangeExpression::DeriveVariable (vtkDataSet *in_ds, int currentDomainsIndex)
{
    char msg[1024];
    double vals[3];
    double out2[9];
    // same as Griz variables
    double x[8], y[8], z[8];         // Initial element geom.
    double xx[8], yy[8], zz[8];      // Current element geom.
    double px[8], py[8], pz[8];      // Global derivates dN/dx,dN/dy,dN/dz.
    double F[9];                     // Element deformation gradient.
    double detF;                     // Determinant of element
                                     // deformation gradient.
    double strain[6];                // Calculated strain.

    std::vector<int> cellsToIgnore;
    double avgTensor[9];             // ghost zone value
    int nTensors = 0;                // number of tensors in average
    
    // Let's get the points from the input dataset.
    if (in_ds->GetDataObjectType() != VTK_UNSTRUCTURED_GRID)
    {
        EXCEPTION2(ExpressionException, outputVariableName,
                   "The strain expression only operates on unstructured grids.");
    }
    vtkUnstructuredGrid *in_usg = vtkUnstructuredGrid::SafeDownCast(in_ds);
    int nCells = in_usg->GetNumberOfCells();
    vtkDataArray *coord_data = in_ds->GetPointData()->GetArray(varnames[1]);
    if (coord_data == NULL)
    {
        sprintf(msg, "The strain expression "
            "could not extract the data array for: %s", varnames[1]);
        EXCEPTION2(ExpressionException, outputVariableName, msg);
    }
    vtkDataArray *ghost_data = in_ds->GetPointData()->GetArray("avtGhostNodes");
    unsigned char *ghost = 
        (unsigned char *) (ghost_data ? ghost_data->GetVoidPointer(0) : 0);
    vtkIdList *pointIds = vtkIdList::New();
    vtkDataArray *out = coord_data->NewInstance();
    out->SetNumberOfComponents(9);
    out->SetNumberOfTuples(nCells);
    for (size_t j = 0; j < 9; j++) 
        avgTensor[j] = 0.0;
    for (size_t i = 0; i < (size_t)nCells; i++)
    {   // Check Voxel format
        int cellType = in_usg->GetCellType(i);
        // ignore everything but hexes
        if (cellType == VTK_HEXAHEDRON)
        {   // Grab a pointer to the cell's points' underlying data array
            in_usg->GetCellPoints(i, pointIds);
            bool anyGhost = false;
            if (ghost)
            {
                for (size_t j = 0; j < 8; j++)
                {
                    if (ghost[pointIds->GetId(j)] != 0)
                    {   // any ghost nodes in this hex
                        anyGhost = true;
                        break;
                    } 
                }
            }                                                 
            if (anyGhost)                                     
            {                                                 
                cellsToIgnore.push_back(i);                   
                continue;                                     
            }
            for (size_t j = 0; j < 8; j++)
            {   // Package initial element geometry points into vtkDataArray
                coord_data->GetTuple(pointIds->GetId(j), vals);
                x[j] = vals[0];
                y[j] = vals[1];
                z[j] = vals[2];
            }
            for (size_t j = 0; j < 8; j++)
            {   // Package current element geometry points into vtkDataArray
                in_usg->GetPoint(pointIds->GetId(j), vals);
                xx[j] = vals[0];
                yy[j] = vals[1];
                zz[j] = vals[2];
            }
            //
            // This is where the strain algorithms start to differ
            avtStrainTensorExpression::HexPartialDerivative
                (px, py, pz, x, y, z);
            for (size_t j = 0; j < 9; j++) 
                F[j] = 0.0;
            // Copied from Griz
            for (size_t  k = 0; k < 8; k++ )
            {          
                F[0] = F[0] + px[k]*xx[k];
                F[1] = F[1] + py[k]*xx[k];
                F[2] = F[2] + pz[k]*xx[k];
                F[3] = F[3] + px[k]*yy[k];
                F[4] = F[4] + py[k]*yy[k];
                F[5] = F[5] + pz[k]*yy[k];
                F[6] = F[6] + px[k]*zz[k];
                F[7] = F[7] + py[k]*zz[k];
                F[8] = F[8] + pz[k]*zz[k]; 
            }   
            detF = F[0]*F[4]*F[8] + F[1]*F[5]*F[6]
                + F[2]*F[3]*F[7] 
                - F[2]*F[4]*F[6] - F[1]*F[3]*F[8]
                - F[0]*F[5]*F[7];
            detF = fabs( detF );
            strain[0] = 0.5*(F[0]*F[0] + F[3]*F[3] + F[6]*F[6] - 1.0);
            strain[1] = 0.5*(F[1]*F[1] + F[4]*F[4] + F[7]*F[7] - 1.0);
            strain[2] = 0.5*(F[2]*F[2] + F[5]*F[5] + F[8]*F[8] - 1.0);
            strain[3] = 0.5*(F[0]*F[1] + F[3]*F[4] + F[6]*F[7] );
            strain[4] = 0.5*(F[1]*F[2] + F[4]*F[5] + F[7]*F[8] );
            strain[5] = 0.5*(F[0]*F[2] + F[3]*F[5] + F[6]*F[8] );
            // End of differences
            //
            // reorder Tensor
            out2[0] = strain[0];  // XX
            out2[1] = strain[3];  // XY
            out2[2] = strain[5];  // XZ
            out2[3] = strain[3];  // YX
            out2[4] = strain[1];  // YY
            out2[5] = strain[4];  // YZ
            out2[6] = strain[5];  // ZX
            out2[7] = strain[4];  // ZY
            out2[8] = strain[2];  // ZZ
            nTensors++;
            for (size_t j = 0; j < 9; j++)
                avgTensor[j] += out2[j];
        } 
        else 
        { // cell is not a hexhedron also ignore              
            cellsToIgnore.push_back(i);
        }
        out->SetTuple(i, out2);
    }
    if (nTensors > 0)
    {   
        for (size_t j = 0; j < 9; j++)
            avgTensor[j] = avgTensor[j]/nTensors;
    }
    for (size_t i = 0; i < cellsToIgnore.size(); i++)
    {   
        out->SetTuple(cellsToIgnore[i], avgTensor);
    }
    return out;
}


// ****************************************************************************
//  Method: avtStrainGreenLagrangeExpression::GetVariableDimension
//
//  Purpose:
//      Determines what the variable dimension of the output is.
//      
//  Programmer: Thomas R. Treadway
//  Creation:   Tue Nov 28 09:56:22 PST 2006
//  
// ****************************************************************************
    
int
avtStrainGreenLagrangeExpression::GetVariableDimension(void)
{
    if (*(GetInput()) == NULL)
        return avtMultipleInputExpressionFilter::GetVariableDimension();
    if (varnames.size() != 2)
        return avtMultipleInputExpressionFilter::GetVariableDimension();
    
    avtDataAttributes &atts = GetInput()->GetInfo().GetAttributes();
    if (! atts.ValidVariable(varnames[0]))
        return avtMultipleInputExpressionFilter::GetVariableDimension();
    int ncomp1 = atts.GetVariableDimension(varnames[0]);
    
    if (! atts.ValidVariable(varnames[1]))
        return avtMultipleInputExpressionFilter::GetVariableDimension();
    int ncomp2 = atts.GetVariableDimension(varnames[1]);
    
    return GetNumberOfComponentsInOutput(ncomp1, ncomp2);
}
