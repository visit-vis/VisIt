#ifndef VISIT_WRITE_DATA_H
#define VISIT_WRITE_DATA_H

#include <string>
#include <vector>
#include <MapNode.h>

class vtkAbstractArray;

class VisItWriteData {
public:
    static void write_data(const std::string &filename, const std::string &varname, vtkAbstractArray *vtkarray);
    static void write_data(const std::string &filename,
			   const stringVector &varnames,
			   const intVector &indices,
			   const intVector &arrayShape,
			   vtkAbstractArray *vtkarray);
};
#endif
