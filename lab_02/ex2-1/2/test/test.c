#include <iostream>
using namespace std;

int main()
{
    int *a;
    a = new int [5];
    for (int i=0; i<5; i++)
       a[i] = i;
    cout << "The address is " << a << endl;
    cout << "a[0] is " << a[0] << endl;
    
    a = a+1;
    cout << "The address is " << a << endl;
    cout << "a[0] is " << a[0] << endl;
    return 0; 
}
