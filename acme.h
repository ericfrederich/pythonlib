#ifndef ACME__H
#define ACME__H

typedef char* (*getterfunc)(char*);
typedef void (*setterfunc)(char*, char*);

setterfunc setitem;
getterfunc getitem;

void setsetter(setterfunc);
void setgetter(getterfunc);

void init();

#endif