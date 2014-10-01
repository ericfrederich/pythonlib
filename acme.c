#include <Python.h>
#include "acme.h"

void init(){
    setenv("PYTHONPATH", ".", 1);
    Py_Initialize();
    PyObject* pName = PyString_FromString("acme");
    PyObject* pAcme = PyImport_Import(pName);
    Py_DECREF(pName);
}

void setsetter(setterfunc x){
    setitem = x;
}
void setgetter(getterfunc x){
    getitem = x;
}
void setdumper(voidfunc x){
    dump = x;
}