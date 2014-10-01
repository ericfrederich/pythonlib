#include <Python.h>

// Python's acme module
PyObject* M_ACME;

void setitem(char* k, char* v){
    // TODO
}

char* getitem(char* k){
    // TODO
    return NULL;
}

void init(){
    Py_Initialize();
    PyObject* pName = PyString_FromString("acme");
    M_ACME = PyImport_Import(pName);
    Py_DECREF(pName);
    printf("%d\n", M_ACME == NULL);
}
