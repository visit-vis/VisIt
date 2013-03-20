#include "VisItWriteData.h"

#include <netcdf>
#include <vtkAbstractArray.h>
#include <vtkDoubleArray.h>

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
			   const stringVector &varnames,
			   const intVector &indices,
			   const intVector &arrayShape,
			   vtkAbstractArray *vtkarray)
{
    vtkDoubleArray *array = vtkDoubleArray::SafeDownCast(vtkarray);

    int ncidp, varidp, dimidsp;
    int nVals = arrayShape[0];
    int nArrs = arrayShape[1];
    int nVars = varnames.size();

    nc_create(filename.c_str(), NC_CLOBBER, &ncidp);
    
    nc_def_dim(ncidp, "x" , nVals, &dimidsp);
    int dims[1] = { dimidsp };
    int *varIds = new int[nVars];

    for (int i = 0; i < nVars; i++)
	nc_def_var(ncidp, varnames[i].c_str(), NC_DOUBLE, 1, dims, &varIds[i]);
    nc_enddef(ncidp);

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
	nc_put_var_double(ncidp, varIds[i], tmp);
    }

    nc_close(ncidp);
    
    delete [] tmp;
    delete [] varIds;
}
