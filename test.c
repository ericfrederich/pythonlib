#include "acme.h"
#include <stdio.h>

int main(int argc, char* argv[]){
    printf("hi\n");
    init();
    setitem("foo", "bar");
    printf("foo is %s\n", getitem("foo"));
    printf("bye\n");
    return 0;
}