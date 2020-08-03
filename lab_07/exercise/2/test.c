#include <iostream>
#include <cstring>

int main()
{
    char *a;
    a = new char [3];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'c';
    std::cout << strlen(a) << std::endl; 
    std::cout << strlen("New York") << std::endl;
    return 0;
}
