#ifndef VISIT_WRITE_DATA_H
#define VISIT_WRITE_DATA_H

#include <string>

class vtkAbstractArray;

class VisItWriteData {
public:
    static void write_data(const std::string &filename, const std::string &varname, vtkAbstractArray *vtkarray);
};
#endif
