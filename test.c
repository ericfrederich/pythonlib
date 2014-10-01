#include "acme.h"
#include <stdio.h>

int main(int argc, char* argv[]){
    init();
    setitem("foo", "bar");
    printf("foo is %s\n", getitem("foo"));
    dump();
    return 0;
}