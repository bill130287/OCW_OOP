// Complex.cpp
#include <iostream>
#include <iomanip>
using namespace std;
#include "Complex.h"
// Member-function definitions for class Complex. 
Complex::Complex()
{
    real = 0.0;
    image = 0.0;
}

Complex::Complex(double R, double Ima)
{
    real = R;
    image = Ima; 
}

Complex::Complex(const Complex &comp)
{
    real = comp.real;
    image = comp.image; 
}
void Complex::assign(double R, double Ima)
{
    real = R;
    image = Ima; 
}

void Complex::printComplex()
{
   cout << fixed << setprecision(1) << "(" << real << ", " << image << ")"; 
}

Complex Complex::add(Complex n1)
{
    Complex result;
    result.real = real + n1.real;
    result.image = image + n1.image;
    
    return result; 
}

Complex Complex::subtract(Complex n1)
{
    Complex result;
    result.real = real - n1.real;
    result.image = image - n1.image;
    
    return result; 
}

Complex Complex::multiply(Complex n1)
{
    Complex result;
    result.real = real * n1.real - image * n1.image;
    result.image = real * n1.image + image * n1.real;

    return result; 
}

Complex Complex::division(Complex n1)
{
    Complex result;
    result.real = (real*n1.real + image*n1.image) / (n1.real*n1.real + n1.image*n1.image);
    result.image = (image*n1.real - real*n1.image) / (n1.real*n1.real + n1.image*n1.image); 
    
    return result;
}

void Complex::assignReal(double R)
{
    real = R; 
}

void Complex::assignImage(double Ima)
{
    image = Ima; 
}

