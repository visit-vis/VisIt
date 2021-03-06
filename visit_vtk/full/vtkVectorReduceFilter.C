/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkVectorReduceFilter.cxx,v $
  Language:  C++
  Date:      $Date: 2001/03/20 14:10:58 $
  Version:   $Revision: 1.1 $
  Thanks:    Hank Childs, B Division, Lawrence Livermore Nat'l Laboratory

Copyright (c) 1993-2000 Ken Martin, Will Schroeder, Bill Lorensen
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * Neither name of Ken Martin, Will Schroeder, or Bill Lorensen nor the names
   of any contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

 * Modified source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/

#include "vtkVectorReduceFilter.h"
#include <vtkCell.h>
#include <vtkCellData.h>
#include <vtkDataSet.h>
#include <vtkDoubleArray.h>
#include <vtkFloatArray.h>
#include <vtkInformation.h>
#include <vtkInformationVector.h>
#include <vtkObjectFactory.h>
#include <vtkPointData.h>
#include <vtkPolyData.h>
#include <vtkVisItUtility.h>

// **************************************************************************
//  Modifications:
//    Kathleen Bonnell, Wed Mar  6 17:10:03 PST 2002 
//    Replace 'New' method with Macro to match VTK 4.0 API.
// **************************************************************************

vtkStandardNewMacro(vtkVectorReduceFilter);


vtkVectorReduceFilter::vtkVectorReduceFilter()
{
  stride = 10;
  numEls = -1;
  origOnly = true;
}

void
vtkVectorReduceFilter::SetStride(int s)
{
  numEls = -1;
  stride = s;
}

void
vtkVectorReduceFilter::SetNumberOfElements(int n)
{
  stride = -1;
  numEls = n;
}

void
vtkVectorReduceFilter::SetLimitToOriginal(bool lto)
{
  origOnly = lto;
}

// ****************************************************************************
//  Modifications:
//    Kathleen Bonnell, Fri Feb  8 11:03:49 PST 2002
//    vtkVectors has been deprecated in VTK 4.0, use 
//    vtkDataArray and vtkFloatArray instead.
//
//    Hank Childs, Wed Apr  9 09:36:07 PDT 2003
//    Made each output vertex also have a VTK_VERTEX in the cell list.
//
//    Kathleen Bonnell, Mon Nov 17 13:58:38 PST 2003 
//    Preserve the name of the Vectors array. 
//
//    Kathleen Bonnell, Thu Aug 12 19:19:28 PDT 2004 
//    Copy other Point and Cell data. 
//
//    Jeremy Meredith, Tue Jul  8 11:07:57 EDT 2008
//    Added ability to limit to only one output vector per original
//    cell/point.  Also, fixed cell-based vector algorithm bugs.
//
//    Hank Childs, Thu Oct 28 22:14:21 PDT 2010
//    Don't output 0-magnitude vectors.
//
//    Kathleen Biagas, Wed Sep 5 13:24:11 MST 2012 
//    Preserve coordinate and vector data types.
//
//    Eric Brugger, Thu Jan 10 10:13:10 PST 2013
//    Modified to inherit from vtkPolyDataAlgorithm.
//
//    Mark C. Miller, Wed Oct  1 19:42:14 PDT 2014
//    Add logic to selectively InsertNextValue(double|float[3]) as well as
//    safely down-cast from double to float to avoid FPE issues.
// ****************************************************************************

int
vtkVectorReduceFilter::RequestData(
  vtkInformation *vtkNotUsed(request),
  vtkInformationVector **inputVector,
  vtkInformationVector *outputVector)
{
  vtkDebugMacro(<<"Executing vtkVectorReduceFilter");

  // get the info objects
  vtkInformation *inInfo = inputVector[0]->GetInformationObject(0);
  vtkInformation *outInfo = outputVector->GetInformationObject(0);
  
  //
  // Initialize some frequently used values.
  //
  vtkDataSet   *input = vtkDataSet::SafeDownCast(
    inInfo->Get(vtkDataObject::DATA_OBJECT()));
  vtkPolyData *output = vtkPolyData::SafeDownCast(
    outInfo->Get(vtkDataObject::DATA_OBJECT()));

  vtkCellData *inCd = input->GetCellData();
  vtkPointData *inPd = input->GetPointData();
  vtkPointData *outPd = output->GetPointData();
  vtkCellData *outCd = output->GetCellData();

  vtkDataArray *inCvecs = inCd->GetVectors();
  vtkDataArray *inPvecs = inPd->GetVectors();

  int npts = input->GetNumberOfPoints();
  int ncells = input->GetNumberOfCells();

  if (inPvecs == NULL && inCvecs == NULL)
    {
    vtkErrorMacro(<<"No vectors to reduce");
    return 1;
    }

  int inctype = (inCvecs ? inCvecs->GetDataType() : VTK_FLOAT);
  int inptype = (inPvecs ? inPvecs->GetDataType() : VTK_FLOAT);

  // Determine what the stride is.
  if (stride <= 0 && numEls <= 0)
    {
    vtkErrorMacro(<<"Invalid stride");
    return 1;
    }

  float actingStride = stride;
  if (actingStride <= 0)
    {
    int totalVecs = 0;
    if (inPvecs != NULL)
    {
        totalVecs += npts;
    }
    if (inCvecs != NULL)
    {
        totalVecs += ncells;
    }
    actingStride = ceil(((float) totalVecs) / ((float) numEls));
    }

  vtkPoints *outpts = vtkVisItUtility::NewPoints(input);
  vtkDataArray *outVecs;
  if (inctype == VTK_DOUBLE || inptype == VTK_DOUBLE)
      outVecs = vtkDoubleArray::New();
  else 
      outVecs = vtkFloatArray::New();
  outVecs->SetNumberOfComponents(3);

  float nextToTake = 0.;
  int count = 0;
  if (inPvecs != NULL)
    {
    bool *foundcell = NULL;
    vtkDataArray *origCellArr =
      input->GetPointData()->GetArray("avtOriginalCellNumbers");
    vtkDataArray *origNodeArr =
      input->GetPointData()->GetArray("avtOriginalNodeNumbers");
    int ccmp = origCellArr ? origCellArr->GetNumberOfComponents() - 1 : -1;
    int ncmp = origNodeArr ? origNodeArr->GetNumberOfComponents() - 1 : -1;

    if (origOnly && origCellArr)
      {
      // Find needed size, allocate, and initialize the "found" array
      int max = 0;
      for (int i=0; i<npts; i++)
        if ((int)origCellArr->GetComponent(i,ccmp) > max)
          max = (int)origCellArr->GetComponent(i,ccmp);
      foundcell = new bool[max+1];
      for (int i=0; i<max+1; i++)
        foundcell[i] = false;
      }

    outPd->CopyAllocate(inPd, npts);
    outVecs->SetName(inPvecs->GetName());
    int index = 0;
    for (int i = 0 ; i < npts ; i++)
      {
      int orignode = i;
      int origcell = -1;
      if (origNodeArr)
        orignode = (int)origNodeArr->GetComponent(i,ncmp);
      if (origCellArr)
        origcell = (int)origCellArr->GetComponent(i,ccmp);

      if (origOnly && orignode<0)
        continue;

      if (foundcell && (origcell<0 || foundcell[origcell]))
        continue;

      if (index >= nextToTake)
        {
        nextToTake += actingStride;

        double v[3];
        inPvecs->GetTuple(i, v);

        if (v[0] != 0. || v[1] != 0. || v[2] != 0.)
          {
            double pt[3];
            input->GetPoint(i, pt);
            outpts->InsertNextPoint(pt);
    
            if (inctype == VTK_DOUBLE || inptype == VTK_DOUBLE)
            {
                outVecs->InsertNextTuple(v);
            }
            else
            {
                float fv[3];
                fv[0] = vtkVisItUtility::SafeDoubleToFloat(v[0]);
                fv[1] = vtkVisItUtility::SafeDoubleToFloat(v[1]);
                fv[2] = vtkVisItUtility::SafeDoubleToFloat(v[2]);
                outVecs->InsertNextTuple(fv);
            }
            outPd->CopyData(inPd, i, count++);
          }
        }

      if (foundcell)
        foundcell[origcell] = true;

      index++;
      }
      outPd->Squeeze();
    }

  nextToTake = 0.;
  count = 0;
  if (inCvecs != NULL && inPvecs == NULL)
    {
    bool *foundcell = NULL;
    vtkDataArray *origCellArr =
      input->GetCellData()->GetArray("avtOriginalCellNumbers");
    int ccmp = origCellArr ? origCellArr->GetNumberOfComponents() - 1 : -1;

    if (origOnly && origCellArr)
    {
      // Find needed size, allocate, and initialize the "found" array
      int max = 0;
      for (int i=0; i<npts; i++)
        if ((int)origCellArr->GetComponent(i,ccmp) > max)
          max = (int)origCellArr->GetComponent(i,ccmp);
      foundcell = new bool[max+1];
      for (int i=0; i<max+1; i++)
        foundcell[i] = false;
    }

    outCd->CopyAllocate(inCd, ncells);
    outVecs->SetName(inCvecs->GetName());
    int index = 0;
    for (int i = 0 ; i < ncells ; i++)
      {
      int origcell = i;
      if (origCellArr)
        origcell = (int)origCellArr->GetComponent(i,ccmp);

      if (foundcell && (origcell<0 || foundcell[origcell]))
        continue;

      if (index >= nextToTake)
        {
        nextToTake += actingStride;

        vtkCell *cell = input->GetCell(i);
        double pt[3];
        vtkVisItUtility::GetCellCenter(cell,pt);
        outpts->InsertNextPoint(pt);

        double v[3];
        inCvecs->GetTuple(i, v);
        outVecs->InsertNextTuple(v);
        outCd->CopyData(inCd, i, count++);
        }

      if (foundcell)
        foundcell[origcell] = true;

      index++;
      }
      outCd->Squeeze();

    if (foundcell)
      delete[] foundcell;
    }

  int nOutPts = outpts->GetNumberOfPoints();
  output->SetPoints(outpts);
  outpts->Delete();
  if (inPvecs)
    output->GetPointData()->SetVectors(outVecs);
  else
    output->GetCellData()->SetVectors(outVecs);
  outVecs->Delete();

  output->Allocate(nOutPts);
  vtkIdType onevertex[1];
  for (int i = 0 ; i < nOutPts ; i++)
    {
    onevertex[0] = i;
    output->InsertNextCell(VTK_VERTEX, 1, onevertex);
    }

  return 1;
}

// ****************************************************************************
//  Method: vtkVectorReduceFilter::FillInputPortInformation
//
// ****************************************************************************

int
vtkVectorReduceFilter::FillInputPortInformation(int, vtkInformation *info)
{
  info->Set(vtkAlgorithm::INPUT_REQUIRED_DATA_TYPE(), "vtkDataSet");
  return 1;
}
  
// ****************************************************************************
//  Method: vtkVectorReduceFilter::PrintSelf
//
// ****************************************************************************

void
vtkVectorReduceFilter::PrintSelf(ostream &os, vtkIndent indent)
{
   this->Superclass::PrintSelf(os, indent);
   os << indent << "Stride: " << this->stride << "\n";
   os << indent << "Target number of vectors: " << this->numEls << "\n";
   os << indent << "Limit to original cell/point: " << this->origOnly << "\n";
}
