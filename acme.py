from cffi import FFI
ffi = FFI()
ffi.cdef("""
    typedef char* (*getterfunc)(char*);
    typedef void (*setterfunc)(char*, char*);
    void setsetter(setterfunc);
    void setgetter(getterfunc);
""")
C = ffi.dlopen(None)  

THE_DATA = {}

# need to keep these or they'll be garbage collected
__c_getitem = ffi.callback("char*(char*)", THE_DATA.__getitem__)
__c_setitem = ffi.callback("void(char*, char*)", THE_DATA.__setitem__)
C.setsetter(__c_setitem)
C.setgetter(__c_getitem)
