// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
/* Write class definition for Complex */
class Complex
{
private: 
    double real;
    double image;

public:
    void assign(double R, double Ima);
    void printComplex();
    Complex add(Complex n1);
    Complex subtract(Complex n1);
    Complex multiply(Complex n1);
    Complex division(Complex n1);
    void assignReal(double R);
    void assignImage(double Ima);
};
#endif 
