#ifndef ACME__H
#define ACME__H

typedef char* (*getterfunc)(char*);
typedef void (*setterfunc)(char*, char*);
typedef void (*voidfunc)(void);

setterfunc setitem;
getterfunc getitem;
voidfunc dump;

void setsetter(setterfunc);
void setgetter(getterfunc);
void setdumper(voidfunc);

void init();

#endif