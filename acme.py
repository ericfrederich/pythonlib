from cffi import FFI
ffi = FFI()
ffi.cdef("""
    typedef char* (*getterfunc)(char*);
    typedef void (*setterfunc)(char*, char*);
    typedef void (*voidfunc)(void);

    void setsetter(setterfunc);
    void setgetter(getterfunc);
    void setdumper(voidfunc);
""")
C = ffi.dlopen(None)  

THE_DATA = {}

# need to keep these or they'll be garbage collected
@ffi.callback("char*(char*)")
def getitem(k):
    k = ffi.string(k)
    return ffi.new("char[]", THE_DATA[k])

@ffi.callback("void(char*, char*)")
def setitem(k, v):
    k, v = map(ffi.string, (k,v))
    THE_DATA[k] = v

C.setgetter(getitem)
C.setsetter(setitem)

@ffi.callback('void(void)')
def dump():
    print THE_DATA

C.setdumper(dump)
