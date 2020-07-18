#include <iostream>
#include "header.h"

int main(int argc, char **argv)
{ 
    school nctu(argv[1]);
    nctu.report(argv[2]);

    return 0;
}
