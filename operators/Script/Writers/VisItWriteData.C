#include "VisItWriteData.h"

#include <netcdf>
#include <vtkAbstractArray.h>
#include <vtkDoubleArray.h>
void
VisItWriteData::write_data(const std::string& filename, const std::string& varname, vtkAbstractArray* vtkarray)
{

    vtkDoubleArray* array = vtkDoubleArray::SafeDownCast(vtkarray);

    std::cout << "writing: " << filename << " " << varname << " "
              << vtkarray->GetDataSize() << " " << vtkarray->GetClassName() <<
                 " " << array->GetNumberOfTuples() << " " << std::endl;

    int ncidp, varidp, dimidsp;

    nc_create(filename.c_str(), NC_CLOBBER ,&ncidp);
    nc_def_dim(ncidp,"x",vtkarray->GetNumberOfTuples(), &dimidsp);
    int dims[1] = { dimidsp };

    nc_def_var(ncidp,varname.c_str(), NC_FLOAT, 1, dims, &varidp);
    nc_enddef(ncidp);

//    size_t start[1] = {0};
//    size_t count[1] = { vtkarray->GetDataSize() };
//    ptrdiff_t stride[1] = {1};
//    ptrdiff_t imap[1] = {1};

    nc_put_var_double(ncidp, varidp, array->GetPointer(0) );
    /*
    nc_put_varm_double(ncidp,
                       varidp,
                       start,
                       count,
                       stride,
                       imap,
                       (double*)vtkarray->GetVoidPointer(0) );
                       */
    nc_close(ncidp);

}
