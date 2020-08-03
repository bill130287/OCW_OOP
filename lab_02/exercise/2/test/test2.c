#include <iostream>
using namespace std;

int mi(const int a, const int b)
{
    int c;
    c = a-b;
    for (int i=0; i<10; i++)
    { 
        if (c > 0)
        {
            return c;
            cout << "mi: " << c << endl; 
        }
        c++;
    }
    cout << "mi break: " << c << endl;
    return c;
    
}

int main()
{
    int a=2, b=50, c = 0;
    c= mi(a, b);
    
    cout << "c: " << c << endl;
    return 0; 
}
