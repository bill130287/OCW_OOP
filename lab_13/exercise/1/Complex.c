// Complex.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Complex.h"
using namespace std;

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

Complex Complex::operator + (const Complex &c1) const
{
    return Complex(real+c1.real, image+c1.image); 
}

Complex Complex::operator - (const Complex &c1) const
{
    return  Complex(real-c1.real, image-c1.image);
}

Complex Complex::operator * (const Complex &c1) const
{
    double R, I;
    R = real*c1.real - image*c1.image;
    I = real*c1.image + image*c1.real;
    return Complex(R, I); 
}

Complex Complex::operator / (const Complex &c1) const
{
    double R, I;
    R = (real*c1.real + image*c1.image) / (c1.real*c1.real + c1.image*c1.image);
    I = (image*c1.real - real*c1.image) / (c1.real*c1.real + c1.image*c1.image);
    return Complex(R, I); 
}
Complex Complex::operator - () const
{
    return Complex(-real, -image); 
}

void printMeg(const Complex &a, const Complex &b, const char &op) 
{
    /*Complex result;

    switch(op)
    {   
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        default:
            cout << "No this " << op << " for Complex";
            break;
    }*/
    printComplex(a);
    cout << " " << op << " ";
    printComplex(b);
    cout << " = ";
    //printComplex(result);
}

void Complex::setComplexNumber(const double &real, const double &image)
{
    this->real = real;
    this->image = image; 
}

void printComplex(const Complex &c1)
{
    cout << fixed << setprecision(1) << "(" << c1.real << ", " << c1.image << ")";  
}

double Complex::Complex_abs() const
{
    return sqrt(real * real + image * image);
}

ostream& operator <<(ostream &out, const Complex &c1)
{
    out << fixed << setprecision(2) << '(' << c1.real << ',' << c1.image << ')' << ' ';
    return out;
}
