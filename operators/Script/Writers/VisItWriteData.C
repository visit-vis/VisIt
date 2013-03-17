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
