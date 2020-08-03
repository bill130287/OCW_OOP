#include <iostream>
#include <vector>
#include <algorithm>
#include "Complex.h"
using namespace std;

double double_random(int range)
{
    return ((RAND_MAX - rand()) / static_cast<double>(RAND_MAX)) * double(range);
}

class Complex_comp
{
public:
    bool operator() (Complex c1, Complex c2)
    {
        return c1.Complex_abs() > c2.Complex_abs(); 
    } 
};

int main()
{
    int n;
    double real = 0, image = 0;
    cout << "Enter n: " << endl;
    cin >> n;

    vector<Complex> vec(n);
    
    srand(103);
    for(int i=0; i<vec.size(); i++)
    {
        real = double_random(10);
        image = double_random(10);
        vec[i].setComplexNumber(real, image); 
    }
    vector<Complex>::const_iterator iter;

    cout << "Original sequence: " << endl;
    for (iter=vec.begin(); iter!=vec.end(); iter++)
    {
        cout << *iter; 
    }
    cout << endl;
    
    sort(vec.begin(), vec.end(), Complex_comp());

    for (iter = vec.begin(); iter!=vec.end(); iter++)
    {
        cout << *iter; 
    }
    cout << endl;


    return 0;    
}
