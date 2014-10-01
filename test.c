#include "acme.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    init();
    setitem("foo", "bar");
    char* val = getitem("foo");
    printf("foo is %s\n", val);
    free(val);
    dump();
    return 0;
}