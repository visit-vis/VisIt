/*****************************************************************************
*
* Copyright (c) 2000 - 2012, Lawrence Livermore National Security, LLC
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

#include <PyScriptAttributes.h>
#include <ObserverToCallback.h>
#include <stdio.h>
#include <snprintf.h>
#include <JSONNode.h>
#include <vectortypes.h>

/// TODO: replace with extern in visitModule if possible..
PyObject* ScriptVisItError = PyErr_NewException((char*)"visit.ScriptException", NULL, NULL);
//PyDict_SetItemString(d, "ScriptException", VisItError);

void
VisItErrorFunc(const char *errString)
{
    PyErr_SetString(ScriptVisItError, errString);
}

bool
GetJSONVectorFromPyObject(PyObject *obj, JSONNode &vec)
{
    bool retval = true;

    if(obj == 0)
    {
        retval = false;
    }
    else if(PyTuple_Check(obj))
    {
        // Extract arguments from the tuple.
        vec = JSONNode::JSONArray();

        for(int i = 0; i < PyTuple_Size(obj); ++i)
        {
            PyObject *item = PyTuple_GET_ITEM(obj, i);
            JSONNode node;
            if(!GetJSONVectorFromPyObject(item,node))
                return false;
            vec.Append(node);
        }
    }
    else if(PyList_Check(obj))
    {
        vec = JSONNode::JSONArray();

        // Extract arguments from the list.
        for(int i = 0; i < PyList_Size(obj); ++i)
        {
            PyObject *item = PyList_GET_ITEM(obj, i);
            JSONNode node;
            if(!GetJSONVectorFromPyObject(item,node))
                return false;
            vec.Append(node);
        }
    }
    else if(PyString_Check(obj))
    {
        vec = PyString_AS_STRING(obj);
    }
    else if(PyInt_Check(obj))
    {
        vec = PyInt_AsLong(obj);
    }
    else if(PyFloat_Check(obj))
    {
        vec = PyFloat_AsDouble(obj);
    }
    else if(PyDict_Check(obj))
    {
        vec = JSONNode::JSONObject();

        PyObject* keys = PyDict_Keys(obj);
        for(int i = 0; i < PyList_Size(keys); ++i)
        {
            PyObject *item = PyList_GET_ITEM(keys, i);
            if(!PyString_Check(item))
            {
                std::cerr << "unknown element type, skipping " << std::endl;
                continue;
            }

            JSONNode node;

            std::string key = PyString_AsString(item);

            PyObject *value = PyDict_GetItem(obj,item);
            if(!GetJSONVectorFromPyObject(value,node))
                return false;
            vec[key] = node;
        }
    }
    else
    {
        retval = false;
        VisItErrorFunc("The object could not be converted to a "
                       "vector of strings.");
    }

    return retval;
}

bool
GetStringVectorFromPyObject(PyObject *obj, stringVector &vec)
{
    bool retval = true;

    if(obj == 0)
    {
        retval = false;
    }
    else if(PyTuple_Check(obj))
    {
        // Extract arguments from the tuple.
        for(int i = 0; i < PyTuple_Size(obj); ++i)
        {
            PyObject *item = PyTuple_GET_ITEM(obj, i);
            if(PyString_Check(item))
                vec.push_back(PyString_AS_STRING(item));
            else
            {
                VisItErrorFunc("The tuple must contain all strings.");
                retval = false;
                break;
            }
        }
    }
    else if(PyList_Check(obj))
    {
        // Extract arguments from the list.
        for(int i = 0; i < PyList_Size(obj); ++i)
        {
            PyObject *item = PyList_GET_ITEM(obj, i);
            if(PyString_Check(item))
                vec.push_back(PyString_AS_STRING(item));
            else
            {
                VisItErrorFunc("The list must contain all strings.");
                retval = false;
                break;
            }
        }
    }
    else if(PyString_Check(obj))
    {
        vec.push_back(PyString_AS_STRING(obj));
    }
    else
    {
        retval = false;
        VisItErrorFunc("The object could not be converted to a "
                       "vector of strings.");
    }

    return retval;
}

// ****************************************************************************
// Module: PyScriptAttributes
//
// Purpose: 
//   ScriptAttributes
//
// Note:       Autogenerated by xml2python. Do not modify by hand!
//
// Programmer: xml2python
// Creation:   omitted
//
// ****************************************************************************

//
// This struct contains the Python type information and a ScriptAttributes.
//
struct ScriptAttributesObject
{
    PyObject_HEAD
    ScriptAttributes *data;
    bool        owns;
    PyObject   *parent;
};

//
// Internal prototypes
//
static PyObject *NewScriptAttributes(int);

std::string
PyScriptAttributes_ToString(const ScriptAttributes *atts, const char *prefix)
{
    if(atts->GetScriptMap().HasEntry("filter"))
        return atts->GetScriptMap().GetEntry("filter")->AsString();
    else
        return atts->GetScriptMap().ToXML();
}

static PyObject *
ScriptAttributes_Notify(PyObject *self, PyObject *args)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)self;
    obj->data->Notify();
    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ScriptAttributes_LoadPythonKernel(PyObject *self, PyObject *args)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)self;

    const char *name = 0;
    const char *code = 0;
    PyObject* arglist = 0;

    if(!PyArg_ParseTuple(args, "sOs", &name,&arglist,&code))
    {
        VisItErrorFunc("Arguments are ('name',('arg1','arg2',...), 'code')");
        return NULL;
    }

    JSONNode node;
    if(!GetJSONVectorFromPyObject(arglist,node))
    {
        VisItErrorFunc("Arguments are ('name',('arg1','arg2',...), 'code')");
        return NULL;
    }

    std::cout << node.ToString() << std::endl;

//    obj->data->AddPythonScript(name,vec,code);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ScriptAttributes_LoadRKernel(PyObject *self, PyObject *args)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)self;

    const char *name = 0;
    const char *code = 0;
    PyObject* arglist = 0;

    if(!PyArg_ParseTuple(args, "sOs", &name,&arglist,&code))
    {
        VisItErrorFunc("Arguments are ('name',('arg1','arg2',...), 'code')");
        return NULL;
    }

    JSONNode node;
    if(!GetJSONVectorFromPyObject(arglist,node))
    {
        VisItErrorFunc("Arguments are ('name',('arg1','arg2',...), 'code')");
        return NULL;
    }

    std::cout << node.ToString() << std::endl;

//    obj->data->AddPythonScript(name,vec,code);

    Py_INCREF(Py_None);
    return Py_None;
}


/*static*/ PyObject *
ScriptAttributes_AddPythonScript(PyObject *self, PyObject *args)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)self;

    const char *name = 0;
    const char *code = 0;
    PyObject* arglist = 0;
    stringVector vec;

    if(!PyArg_ParseTuple(args, "sOs", &name,&arglist,&code))
    {
        VisItErrorFunc("Arguments are ('name',('arg1','arg2',...), 'code')");
        return NULL;
    }

    if(!GetStringVectorFromPyObject(arglist,vec))
    {
        VisItErrorFunc("Arguments are ('name',('arg1','arg2',...), 'code')");
        return NULL;
    }

    obj->data->AddPythonScript(name,vec,code);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ScriptAttributes_AddRScript(PyObject *self, PyObject *args)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)self;

    const char *name = 0;
    const char *code = 0;
    PyObject* arglist = 0;
    stringVector vec;

    if(!PyArg_ParseTuple(args, "sOs", &name,&arglist,&code))
    {
        VisItErrorFunc("Arguments are ('name',('arg1','arg2',...), 'code')");
        return NULL;
    }

    if(!GetStringVectorFromPyObject(arglist,vec))
    {
        VisItErrorFunc("Arguments are ('name',('arg1','arg2',...), 'code')");
        return NULL;
    }

    obj->data->AddRScript(name,vec,code);
    Py_INCREF(Py_None);
    return Py_None;
}


/*static*/ PyObject *
ScriptAttributes_AddFunction(PyObject *self, PyObject *args)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)self;

    const char *name = 0;
    PyObject* arglist = 0;
    stringVector vec;

    if(!PyArg_ParseTuple(args, "sO", &name,&arglist))
    {
        VisItErrorFunc("Arguments are ('name',('arg1','arg2',...))");
        return NULL;
    }

    if(!GetStringVectorFromPyObject(arglist,vec))
    {
        VisItErrorFunc("Arguments are ('name',('arg1','arg2',...))");
        return NULL;
    }

    obj->data->AddFunction(name,vec);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ScriptAttributes_AddConstant(PyObject *self, PyObject *args)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)self;

    const char *name = 0;
    const char *constant = 0;


    if(!PyArg_ParseTuple(args, "ss", &name,&constant))
    {
        VisItErrorFunc("Arguments are ('name', 'constant')");
        return NULL;
    }

    obj->data->AddConstant(name,constant);

    Py_INCREF(Py_None);
    return Py_None;
}


/*static*/ PyObject *
ScriptAttributes_AddNode(PyObject *self, PyObject *args)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)self;
    const char* name = 0;
    const char* type = 0;
    //wrap this in a function..
    if(!PyArg_ParseTuple(args, "ss", &name,&type))
    {
        VisItErrorFunc("Arguments are ('name', '[script_name|as_ndarray|as_vtkarray|as_rarray]')");
        return NULL;
    }

    obj->data->AddNode(name,type);

    /*
    std::string node_type = type;
    if(!obj->node["scripts"].HasKey(node_type) &&
             node_type != "as_ndarray" &&
             node_type != "as_vtkarray" &&
             node_type != "as_rarray")
    {
        VisItErrorFunc("Type must be [script_name|as_ndarray|as_vtkarray|as_rarray]')");
        return NULL;
    }

    JSONNode node;
    node["type"] = node_type;
    obj->node["nodes"][name] = node;

    MapNode mapnode;
    mapnode["filter"] = obj->node.ToString();
    obj->data->SetScriptMap(mapnode);
    */
    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ScriptAttributes_AddConnection(PyObject *self, PyObject *args)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)self;

    const char* from = 0;
    const char* to = 0;
    const char* port = 0;

    if(!PyArg_ParseTuple(args, "sss", &from,&to,&port))
    {
        VisItErrorFunc("Arguments are ('from_node', 'to_node', 'connection_name')");
        return NULL;
    }

    obj->data->AddConnection(from,to,port);
    /// TODO: error check input & output ports..

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ScriptAttributes_AddFinalOutputConnection(PyObject *self, PyObject *args)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)self;

    const char* from = 0;
    if(!PyArg_ParseTuple(args, "s", &from))
    {
        VisItErrorFunc("Arguments are ('from_node')");
        return NULL;
    }

    obj->data->AddFinalOutputConnection(from);

    Py_INCREF(Py_None);
    return Py_None;
}

/*static*/ PyObject *
ScriptAttributes_GetScriptMap(PyObject *self, PyObject *args)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)self;
    PyObject *retval = PyString_FromString(obj->data->GetScriptMap().AsString().c_str());
    return retval;
}


PyMethodDef PyScriptAttributes_methods[SCRIPTATTRIBUTES_NMETH] = {
    {"Notify", ScriptAttributes_Notify, METH_VARARGS},

    /// script functions..
    {"AddPythonScript", ScriptAttributes_AddPythonScript, METH_VARARGS},
    {"AddRScript", ScriptAttributes_AddRScript, METH_VARARGS},
    {"AddVisItFunction", ScriptAttributes_AddFunction, METH_VARARGS},
    {"AddConstant", ScriptAttributes_AddConstant, METH_VARARGS},

    {"AddNode", ScriptAttributes_AddNode, METH_VARARGS},

    {"AddConnection", ScriptAttributes_AddConnection, METH_VARARGS},
    {"AddFinalOutputConnection", ScriptAttributes_AddFinalOutputConnection, METH_VARARGS},

    /// GetScriptMap
    {"GetScriptMap", ScriptAttributes_GetScriptMap, METH_VARARGS},

    {"LoadPythonKernel", ScriptAttributes_LoadPythonKernel, METH_VARARGS},
    {"LoadRKernel", ScriptAttributes_LoadRKernel, METH_VARARGS},

    {NULL, NULL}
};

//
// Type functions
//

static void
ScriptAttributes_dealloc(PyObject *v)
{
   ScriptAttributesObject *obj = (ScriptAttributesObject *)v;
   if(obj->parent != 0)
       Py_DECREF(obj->parent);
   if(obj->owns)
       delete obj->data;
}

static int
ScriptAttributes_compare(PyObject *v, PyObject *w)
{
    ScriptAttributes *a = ((ScriptAttributesObject *)v)->data;
    ScriptAttributes *b = ((ScriptAttributesObject *)w)->data;
    return (*a == *b) ? 0 : -1;
}

PyObject *
PyScriptAttributes_getattr(PyObject *self, char *name)
{
    if(strcmp(name, "scriptMap") == 0)
        return ScriptAttributes_GetScriptMap(self, NULL);

    return Py_FindMethod(PyScriptAttributes_methods, self, name);
}

int
PyScriptAttributes_setattr(PyObject *self, char *name, PyObject *args)
{
    // Create a tuple to contain the arguments since all of the Set
    // functions expect a tuple.
    PyObject *tuple = PyTuple_New(1);
    PyTuple_SET_ITEM(tuple, 0, args);
    Py_INCREF(args);
    PyObject *obj = NULL;

    if(strcmp(name, "scriptMap") == 0)
           obj = ScriptAttributes_GetScriptMap(self, tuple);

    if(obj != NULL)
        Py_DECREF(obj);

    Py_DECREF(tuple);
    if( obj == NULL)
        PyErr_Format(PyExc_RuntimeError, "Unable to set unknown attribute: '%s'", name);
    return (obj != NULL) ? 0 : -1;
}

static int
ScriptAttributes_print(PyObject *v, FILE *fp, int flags)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)v;
    fprintf(fp, "%s", PyScriptAttributes_ToString(obj->data, "").c_str());
    return 0;
}

PyObject *
ScriptAttributes_str(PyObject *v)
{
    ScriptAttributesObject *obj = (ScriptAttributesObject *)v;
    return PyString_FromString(PyScriptAttributes_ToString(obj->data,"").c_str());
}

//
// The doc string for the class.
//
#if PY_MAJOR_VERSION > 2 || (PY_MAJOR_VERSION == 2 && PY_MINOR_VERSION >= 5)
static const char *ScriptAttributes_Purpose = "ScriptAttributes";
#else
static char *ScriptAttributes_Purpose = "ScriptAttributes";
#endif

//
// The type description structure
//
static PyTypeObject ScriptAttributesType =
{
    //
    // Type header
    //
    PyObject_HEAD_INIT(&PyType_Type)
    0,                                   // ob_size
    "ScriptAttributes",                    // tp_name
    sizeof(ScriptAttributesObject),        // tp_basicsize
    0,                                   // tp_itemsize
    //
    // Standard methods
    //
    (destructor)ScriptAttributes_dealloc,  // tp_dealloc
    (printfunc)ScriptAttributes_print,     // tp_print
    (getattrfunc)PyScriptAttributes_getattr, // tp_getattr
    (setattrfunc)PyScriptAttributes_setattr, // tp_setattr
    (cmpfunc)ScriptAttributes_compare,     // tp_compare
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
    (reprfunc)ScriptAttributes_str,        // tp_str
    0,                                   // tp_getattro
    0,                                   // tp_setattro
    0,                                   // tp_as_buffer
    Py_TPFLAGS_CHECKTYPES,               // tp_flags
    ScriptAttributes_Purpose,              // tp_doc
    0,                                   // tp_traverse
    0,                                   // tp_clear
    0,                                   // tp_richcompare
    0                                    // tp_weaklistoffset
};

//
// Helper functions for object allocation.
//

static ScriptAttributes *defaultAtts = 0;
static ScriptAttributes *currentAtts = 0;

static PyObject *
NewScriptAttributes(int useCurrent)
{
    ScriptAttributesObject *newObject;
    newObject = PyObject_NEW(ScriptAttributesObject, &ScriptAttributesType);
    if(newObject == NULL)
        return NULL;
    if(useCurrent && currentAtts != 0)
        newObject->data = new ScriptAttributes(*currentAtts);
    else if(defaultAtts != 0)
        newObject->data = new ScriptAttributes(*defaultAtts);
    else
        newObject->data = new ScriptAttributes;
    newObject->owns = true;
    newObject->parent = 0;
    return (PyObject *)newObject;
}

static PyObject *
WrapScriptAttributes(const ScriptAttributes *attr)
{
    ScriptAttributesObject *newObject;
    newObject = PyObject_NEW(ScriptAttributesObject, &ScriptAttributesType);
    if(newObject == NULL)
        return NULL;
    newObject->data = (ScriptAttributes *)attr;
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
ScriptAttributes_new(PyObject *self, PyObject *args)
{
    int useCurrent = 0;
    if (!PyArg_ParseTuple(args, "i", &useCurrent))
    {
        if (!PyArg_ParseTuple(args, ""))
            return NULL;
        else
            PyErr_Clear();
    }

    return (PyObject *)NewScriptAttributes(useCurrent);
}

//
// Plugin method table. These methods are added to the visitmodule's methods.
//
static PyMethodDef ScriptAttributesMethods[] = {
    {"ScriptAttributes", ScriptAttributes_new, METH_VARARGS},
    {NULL,      NULL}        /* Sentinel */
};

static Observer *ScriptAttributesObserver = 0;

std::string
PyScriptAttributes_GetLogString()
{
    std::string s("ScriptAtts = ScriptAttributes()\n");
    if(currentAtts != 0)
        s += PyScriptAttributes_ToString(currentAtts, "ScriptAtts.");
    return s;
}

static void
PyScriptAttributes_CallLogRoutine(Subject *subj, void *data)
{
    ScriptAttributes *atts = (ScriptAttributes *)subj;
    typedef void (*logCallback)(const std::string &);
    logCallback cb = (logCallback)data;

    if(cb != 0)
    {
        std::string s("ScriptAtts = ScriptAttributes()\n");
        s += PyScriptAttributes_ToString(currentAtts, "ScriptAtts.");
        cb(s);
    }
}

void
PyScriptAttributes_StartUp(ScriptAttributes *subj, void *data)
{
    if(subj == 0)
        return;

    currentAtts = subj;
    PyScriptAttributes_SetDefaults(subj);

    //
    // Create the observer that will be notified when the attributes change.
    //
    if(ScriptAttributesObserver == 0)
    {
        ScriptAttributesObserver = new ObserverToCallback(subj,
            PyScriptAttributes_CallLogRoutine, (void *)data);
    }

}

void
PyScriptAttributes_CloseDown()
{
    delete defaultAtts;
    defaultAtts = 0;
    delete ScriptAttributesObserver;
    ScriptAttributesObserver = 0;
}

PyMethodDef *
PyScriptAttributes_GetMethodTable(int *nMethods)
{
    *nMethods = 1;
    return ScriptAttributesMethods;
}

bool
PyScriptAttributes_Check(PyObject *obj)
{
    return (obj->ob_type == &ScriptAttributesType);
}

ScriptAttributes *
PyScriptAttributes_FromPyObject(PyObject *obj)
{
    ScriptAttributesObject *obj2 = (ScriptAttributesObject *)obj;
    return obj2->data;
}

PyObject *
PyScriptAttributes_New()
{
    return NewScriptAttributes(0);
}

PyObject *
PyScriptAttributes_Wrap(const ScriptAttributes *attr)
{
    return WrapScriptAttributes(attr);
}

void
PyScriptAttributes_SetParent(PyObject *obj, PyObject *parent)
{
    ScriptAttributesObject *obj2 = (ScriptAttributesObject *)obj;
    obj2->parent = parent;
}

void
PyScriptAttributes_SetDefaults(const ScriptAttributes *atts)
{
    if(defaultAtts)
        delete defaultAtts;

    defaultAtts = new ScriptAttributes(*atts);
}

