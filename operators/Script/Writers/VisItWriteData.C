#include "VisItWriteData.h"

#include <netcdf>
#include <vtkAbstractArray.h>
#include <vtkDoubleArray.h>

#include <string>
#include <vector>

void
VisItWriteData::write_data(const std::string& filename, const std::string& varname, vtkAbstractArray* vtkarray)
{

    vtkDoubleArray* array = vtkDoubleArray::SafeDownCast(vtkarray);

    std::cout << "netcdf: " << filename << " " << varname << " "
              << vtkarray->GetDataSize() << " " << vtkarray->GetClassName() << " "
              << array->GetNumberOfTuples() << " " << std::endl;

    int ncidp, varidp, dimidsp;

    nc_create(filename.c_str(), NC_CLOBBER ,&ncidp);
    nc_def_dim(ncidp,"x",vtkarray->GetNumberOfTuples(), &dimidsp);
    int dims[1] = { dimidsp };

    nc_def_var(ncidp,varname.c_str(), NC_DOUBLE, 1, dims, &varidp);
    nc_enddef(ncidp);

    nc_put_var_double(ncidp, varidp, array->GetPointer(0) );
    nc_close(ncidp);
}

void
VisItWriteData::write_data(const std::string &filename,
			   const stringVector &dimNm,
			   const std::vector<std::vector<double> > &dimensions,
			   const stringVector &varnames,
			   const intVector &indices,
			   const intVector &arrayShape,
			   vtkAbstractArray *vtkarray)
{
    vtkDoubleArray *array = vtkDoubleArray::SafeDownCast(vtkarray);

    int ncID;
    int nVals = arrayShape[0];
    int nArrs = arrayShape[1];
    int nVars = varnames.size();
    int nDims = dimensions.size();

    nc_create(filename.c_str(), NC_CLOBBER, &ncID);
    //Define dimensions.
    int *dimIds = new int[nDims];
    for (int i = 0; i < nDims; i++)
	nc_def_dim(ncID, dimNm[i].c_str() , dimensions[i].size(), &dimIds[i]);

    //Define vars.
    int *dimVarIds = new int[nDims];
    for (int i = 0; i < nDims; i++)
	nc_def_var(ncID, dimNm[i].c_str(), NC_DOUBLE, 1, &dimIds[i], &dimVarIds[i]);

    //Reverse the dim ordering...
    int *swapIds = new int[nDims];
    for (int i = 0; i < nDims; i++)
	swapIds[i] = dimIds[nDims-1 -i];
    for (int i = 0; i < nDims; i++)
	dimIds[i] = swapIds[i];
    delete [] swapIds;

    int *varIds = new int[nVars];
    for (int i = 0; i < nVars; i++)
	nc_def_var(ncID, varnames[i].c_str(), NC_DOUBLE, nDims, dimIds, &varIds[i]);

    nc_enddef(ncID);

    //dump out dim values.
    for (int i = 0; i < nDims; i++)
    {
	double *d = new double[dimensions[i].size()];
	for (int j = 0; j < dimensions[i].size(); j++)
	    d[j] = dimensions[i][j];
	nc_put_var_double(ncID, dimVarIds[i], d);
	delete [] d;
    }

    size_t start[1] = {0}, count[1] = {nVals};
    ptrdiff_t stride[1] = {nArrs};
    stride[0] = 0;

    double *tmp = new double[nVals];
    for (int i = 0; i < nVars; i++)
    {
	double *ptr = array->GetPointer(indices[i]);
	int counter = indices[i];
	for (int j = 0; j < nVals; j++)
	{
	    tmp[j] = *ptr;
	    ptr += nArrs;
	}
	nc_put_var_double(ncID, varIds[i], tmp);
    }
    nc_close(ncID);
    
    delete [] tmp;
    delete [] varIds;
    delete [] dimVarIds;
    delete [] dimIds;
}
