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

#include <PyavtMatSpeciesMetaData.h>
#include <ObserverToCallback.h>
#include <stdio.h>
#include <snprintf.h>

// ****************************************************************************
// Module: PyavtMatSpeciesMetaData
//
// Purpose: 
//   Contains material species metadata attributes
//
// Note:       Autogenerated by xml2python. Do not modify by hand!
//
// Programmer: xml2python
// Creation:   omitted
//
// ****************************************************************************

//
// This struct contains the Python type information and a avtMatSpeciesMetaData.
//
struct avtMatSpeciesMetaDataObject
{
    PyObject_HEAD
    avtMatSpeciesMetaData *data;
    bool        owns;
    PyObject   *parent;
};

//
// Internal prototypes
//
static PyObject *NewavtMatSpeciesMetaData(int);

std::string
PyavtMatSpeciesMetaData_ToString(const avtMatSpeciesMetaData *atts, const char *prefix)
{
    std::string str;
    char tmpStr[1000];

    SNPRINTF(tmpStr, 1000, "%snumSpecies = %d\n", prefix, atts->numSpecies);
    str += tmpStr;
    {   const stringVector &speciesNames = atts->speciesNames;
        SNPRINTF(tmpStr, 1000, "%sspeciesNames = (", prefix);
        str += tmpStr;
        for(size_t i = 0; i < speciesNames.size(); ++i)
        {
            SNPRINTF(tmpStr, 1000, "\"%s\"", speciesNames[i].c_str());
            str += tmpStr;
            if(i < speciesNames.size() - 1)
            {
                SNPRINTF(tmpStr, 1000, ", ");
                str += tmpStr;
            }
        }
        SNPRINTF(tmpStr, 1000, ")\n");
        str += tmpStr;
    }
    if(atts->validVariable)
        SNPRINTF(tmpStr, 1000, "%svalidVariable = 1\n", prefix);
    else
        SNPRINTF(tmpStr, 1000, "%svalidVariable = 0\n", prefix);
    str += tmpStr;
    return str;
}

static PyObject *
avtMatSpeciesMetaData_Notify(PyObject *self, PyObject *args)
{
    avtMatSpeciesMetaDataObject *obj = (avtMatSpeciesMetaDataObject *)self;
    obj->data->Notify();
    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
avtMatSpeciesMetaData_SetNumSpecies(PyObject *self, PyObject *args)
{
    avtMatSpeciesMetaDataObject *obj = (avtMatSpeciesMetaDataObject *)self;

    int ival;
    if(!PyArg_ParseTuple(args, "i", &ival))
        return NULL;

    // Set the numSpecies in the object.
    obj->data->numSpecies = (int)ival;

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
avtMatSpeciesMetaData_GetNumSpecies(PyObject *self, PyObject *args)
{
    avtMatSpeciesMetaDataObject *obj = (avtMatSpeciesMetaDataObject *)self;
    PyObject *retval = PyInt_FromLong(long(obj->data->numSpecies));
    return retval;
}

/*static*/ PyObject *
avtMatSpeciesMetaData_SetSpeciesNames(PyObject *self, PyObject *args)
{
    avtMatSpeciesMetaDataObject *obj = (avtMatSpeciesMetaDataObject *)self;

    stringVector  &vec = obj->data->speciesNames;
    PyObject     *tuple;
    if(!PyArg_ParseTuple(args, "O", &tuple))
        return NULL;

    if(PyTuple_Check(tuple))
    {
        vec.resize(PyTuple_Size(tuple));
        for(int i = 0; i < PyTuple_Size(tuple); ++i)
        {
            PyObject *item = PyTuple_GET_ITEM(tuple, i);
            if(PyString_Check(item))
                vec[i] = std::string(PyString_AS_STRING(item));
            else
                vec[i] = std::string("");
        }
    }
    else if(PyString_Check(tuple))
    {
        vec.resize(1);
        vec[0] = std::string(PyString_AS_STRING(tuple));
    }
    else
        return NULL;

    // Mark the speciesNames in the object as modified.
    obj->data->SelectAll();

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
avtMatSpeciesMetaData_GetSpeciesNames(PyObject *self, PyObject *args)
{
    avtMatSpeciesMetaDataObject *obj = (avtMatSpeciesMetaDataObject *)self;
    // Allocate a tuple the with enough entries to hold the speciesNames.
    const stringVector &speciesNames = obj->data->speciesNames;
    PyObject *retval = PyTuple_New(speciesNames.size());
    for(size_t i = 0; i < speciesNames.size(); ++i)
        PyTuple_SET_ITEM(retval, i, PyString_FromString(speciesNames[i].c_str()));
    return retval;
}

/*static*/ PyObject *
avtMatSpeciesMetaData_SetValidVariable(PyObject *self, PyObject *args)
{
    avtMatSpeciesMetaDataObject *obj = (avtMatSpeciesMetaDataObject *)self;

    int ival;
    if(!PyArg_ParseTuple(args, "i", &ival))
        return NULL;

    // Set the validVariable in the object.
    obj->data->validVariable = (ival != 0);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
avtMatSpeciesMetaData_GetValidVariable(PyObject *self, PyObject *args)
{
    avtMatSpeciesMetaDataObject *obj = (avtMatSpeciesMetaDataObject *)self;
    PyObject *retval = PyInt_FromLong(obj->data->validVariable?1L:0L);
    return retval;
}



PyMethodDef PyavtMatSpeciesMetaData_methods[AVTMATSPECIESMETADATA_NMETH] = {
    {"Notify", avtMatSpeciesMetaData_Notify, METH_VARARGS},
    {"SetNumSpecies", avtMatSpeciesMetaData_SetNumSpecies, METH_VARARGS},
    {"GetNumSpecies", avtMatSpeciesMetaData_GetNumSpecies, METH_VARARGS},
    {"SetSpeciesNames", avtMatSpeciesMetaData_SetSpeciesNames, METH_VARARGS},
    {"GetSpeciesNames", avtMatSpeciesMetaData_GetSpeciesNames, METH_VARARGS},
    {"SetValidVariable", avtMatSpeciesMetaData_SetValidVariable, METH_VARARGS},
    {"GetValidVariable", avtMatSpeciesMetaData_GetValidVariable, METH_VARARGS},
    {NULL, NULL}
};

//
// Type functions
//

static void
avtMatSpeciesMetaData_dealloc(PyObject *v)
{
   avtMatSpeciesMetaDataObject *obj = (avtMatSpeciesMetaDataObject *)v;
   if(obj->parent != 0)
       Py_DECREF(obj->parent);
   if(obj->owns)
       delete obj->data;
}

static int
avtMatSpeciesMetaData_compare(PyObject *v, PyObject *w)
{
    avtMatSpeciesMetaData *a = ((avtMatSpeciesMetaDataObject *)v)->data;
    avtMatSpeciesMetaData *b = ((avtMatSpeciesMetaDataObject *)w)->data;
    return (*a == *b) ? 0 : -1;
}

PyObject *
PyavtMatSpeciesMetaData_getattr(PyObject *self, char *name)
{
    if(strcmp(name, "numSpecies") == 0)
        return avtMatSpeciesMetaData_GetNumSpecies(self, NULL);
    if(strcmp(name, "speciesNames") == 0)
        return avtMatSpeciesMetaData_GetSpeciesNames(self, NULL);
    if(strcmp(name, "validVariable") == 0)
        return avtMatSpeciesMetaData_GetValidVariable(self, NULL);

    return Py_FindMethod(PyavtMatSpeciesMetaData_methods, self, name);
}

int
PyavtMatSpeciesMetaData_setattr(PyObject *self, char *name, PyObject *args)
{
    // Create a tuple to contain the arguments since all of the Set
    // functions expect a tuple.
    PyObject *tuple = PyTuple_New(1);
    PyTuple_SET_ITEM(tuple, 0, args);
    Py_INCREF(args);
    PyObject *obj = NULL;

    if(strcmp(name, "numSpecies") == 0)
        obj = avtMatSpeciesMetaData_SetNumSpecies(self, tuple);
    else if(strcmp(name, "speciesNames") == 0)
        obj = avtMatSpeciesMetaData_SetSpeciesNames(self, tuple);
    else if(strcmp(name, "validVariable") == 0)
        obj = avtMatSpeciesMetaData_SetValidVariable(self, tuple);

    if(obj != NULL)
        Py_DECREF(obj);

    Py_DECREF(tuple);
    if( obj == NULL)
        PyErr_Format(PyExc_RuntimeError, "Unable to set unknown attribute: '%s'", name);
    return (obj != NULL) ? 0 : -1;
}

static int
avtMatSpeciesMetaData_print(PyObject *v, FILE *fp, int flags)
{
    avtMatSpeciesMetaDataObject *obj = (avtMatSpeciesMetaDataObject *)v;
    fprintf(fp, "%s", PyavtMatSpeciesMetaData_ToString(obj->data, "").c_str());
    return 0;
}

PyObject *
avtMatSpeciesMetaData_str(PyObject *v)
{
    avtMatSpeciesMetaDataObject *obj = (avtMatSpeciesMetaDataObject *)v;
    return PyString_FromString(PyavtMatSpeciesMetaData_ToString(obj->data,"").c_str());
}

//
// The doc string for the class.
//
#if PY_MAJOR_VERSION > 2 || (PY_MAJOR_VERSION == 2 && PY_MINOR_VERSION >= 5)
static const char *avtMatSpeciesMetaData_Purpose = "Contains material species metadata attributes";
#else
static char *avtMatSpeciesMetaData_Purpose = "Contains material species metadata attributes";
#endif

//
// The type description structure
//
static PyTypeObject avtMatSpeciesMetaDataType =
{
    //
    // Type header
    //
    PyObject_HEAD_INIT(&PyType_Type)
    0,                                   // ob_size
    "avtMatSpeciesMetaData",                    // tp_name
    sizeof(avtMatSpeciesMetaDataObject),        // tp_basicsize
    0,                                   // tp_itemsize
    //
    // Standard methods
    //
    (destructor)avtMatSpeciesMetaData_dealloc,  // tp_dealloc
    (printfunc)avtMatSpeciesMetaData_print,     // tp_print
    (getattrfunc)PyavtMatSpeciesMetaData_getattr, // tp_getattr
    (setattrfunc)PyavtMatSpeciesMetaData_setattr, // tp_setattr
    (cmpfunc)avtMatSpeciesMetaData_compare,     // tp_compare
    (reprfunc)0,                         // tp_repr
    //
    // Type categories
    //
    0,                                   // tp_as_number
    0,                                   // tp_as_sequence
    0,                                   // tp_as_mapping
    //
    // More methods
    //
    0,                                   // tp_hash
    0,                                   // tp_call
    (reprfunc)avtMatSpeciesMetaData_str,        // tp_str
    0,                                   // tp_getattro
    0,                                   // tp_setattro
    0,                                   // tp_as_buffer
    Py_TPFLAGS_CHECKTYPES,               // tp_flags
    avtMatSpeciesMetaData_Purpose,              // tp_doc
    0,                                   // tp_traverse
    0,                                   // tp_clear
    0,                                   // tp_richcompare
    0                                    // tp_weaklistoffset
};

//
// Helper functions for object allocation.
//

static avtMatSpeciesMetaData *defaultAtts = 0;
static avtMatSpeciesMetaData *currentAtts = 0;

static PyObject *
NewavtMatSpeciesMetaData(int useCurrent)
{
    avtMatSpeciesMetaDataObject *newObject;
    newObject = PyObject_NEW(avtMatSpeciesMetaDataObject, &avtMatSpeciesMetaDataType);
    if(newObject == NULL)
        return NULL;
    if(useCurrent && currentAtts != 0)
        newObject->data = new avtMatSpeciesMetaData(*currentAtts);
    else if(defaultAtts != 0)
        newObject->data = new avtMatSpeciesMetaData(*defaultAtts);
    else
        newObject->data = new avtMatSpeciesMetaData;
    newObject->owns = true;
    newObject->parent = 0;
    return (PyObject *)newObject;
}

static PyObject *
WrapavtMatSpeciesMetaData(const avtMatSpeciesMetaData *attr)
{
    avtMatSpeciesMetaDataObject *newObject;
    newObject = PyObject_NEW(avtMatSpeciesMetaDataObject, &avtMatSpeciesMetaDataType);
    if(newObject == NULL)
        return NULL;
    newObject->data = (avtMatSpeciesMetaData *)attr;
    newObject->owns = false;
    newObject->parent = 0;
    return (PyObject *)newObject;
}

///////////////////////////////////////////////////////////////////////////////
//
// Interface that is exposed to the VisIt module.
//
///////////////////////////////////////////////////////////////////////////////

PyObject *
avtMatSpeciesMetaData_new(PyObject *self, PyObject *args)
{
    int useCurrent = 0;
    if (!PyArg_ParseTuple(args, "i", &useCurrent))
    {
        if (!PyArg_ParseTuple(args, ""))
            return NULL;
        else
            PyErr_Clear();
    }

    return (PyObject *)NewavtMatSpeciesMetaData(useCurrent);
}

//
// Plugin method table. These methods are added to the visitmodule's methods.
//
static PyMethodDef avtMatSpeciesMetaDataMethods[] = {
    {"avtMatSpeciesMetaData", avtMatSpeciesMetaData_new, METH_VARARGS},
    {NULL,      NULL}        /* Sentinel */
};

static Observer *avtMatSpeciesMetaDataObserver = 0;

std::string
PyavtMatSpeciesMetaData_GetLogString()
{
    std::string s("avtMatSpeciesMetaData = avtMatSpeciesMetaData()\n");
    if(currentAtts != 0)
        s += PyavtMatSpeciesMetaData_ToString(currentAtts, "avtMatSpeciesMetaData.");
    return s;
}

static void
PyavtMatSpeciesMetaData_CallLogRoutine(Subject *subj, void *data)
{
    typedef void (*logCallback)(const std::string &);
    logCallback cb = (logCallback)data;

    if(cb != 0)
    {
        std::string s("avtMatSpeciesMetaData = avtMatSpeciesMetaData()\n");
        s += PyavtMatSpeciesMetaData_ToString(currentAtts, "avtMatSpeciesMetaData.");
        cb(s);
    }
}

void
PyavtMatSpeciesMetaData_StartUp(avtMatSpeciesMetaData *subj, void *data)
{
    if(subj == 0)
        return;

    currentAtts = subj;
    PyavtMatSpeciesMetaData_SetDefaults(subj);

    //
    // Create the observer that will be notified when the attributes change.
    //
    if(avtMatSpeciesMetaDataObserver == 0)
    {
        avtMatSpeciesMetaDataObserver = new ObserverToCallback(subj,
            PyavtMatSpeciesMetaData_CallLogRoutine, (void *)data);
    }

}

void
PyavtMatSpeciesMetaData_CloseDown()
{
    delete defaultAtts;
    defaultAtts = 0;
    delete avtMatSpeciesMetaDataObserver;
    avtMatSpeciesMetaDataObserver = 0;
}

PyMethodDef *
PyavtMatSpeciesMetaData_GetMethodTable(int *nMethods)
{
    *nMethods = 1;
    return avtMatSpeciesMetaDataMethods;
}

bool
PyavtMatSpeciesMetaData_Check(PyObject *obj)
{
    return (obj->ob_type == &avtMatSpeciesMetaDataType);
}

avtMatSpeciesMetaData *
PyavtMatSpeciesMetaData_FromPyObject(PyObject *obj)
{
    avtMatSpeciesMetaDataObject *obj2 = (avtMatSpeciesMetaDataObject *)obj;
    return obj2->data;
}

PyObject *
PyavtMatSpeciesMetaData_New()
{
    return NewavtMatSpeciesMetaData(0);
}

PyObject *
PyavtMatSpeciesMetaData_Wrap(const avtMatSpeciesMetaData *attr)
{
    return WrapavtMatSpeciesMetaData(attr);
}

void
PyavtMatSpeciesMetaData_SetParent(PyObject *obj, PyObject *parent)
{
    avtMatSpeciesMetaDataObject *obj2 = (avtMatSpeciesMetaDataObject *)obj;
    obj2->parent = parent;
}

void
PyavtMatSpeciesMetaData_SetDefaults(const avtMatSpeciesMetaData *atts)
{
    if(defaultAtts)
        delete defaultAtts;

    defaultAtts = new avtMatSpeciesMetaData(*atts);
}

