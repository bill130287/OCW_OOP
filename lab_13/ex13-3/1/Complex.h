// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
/* Write class definition for Complex */
using std::ostream;

class Complex
{
private: 
    double real;
    double image;

public:
    Complex();
    Complex(double R, double Ima);
    Complex(const Complex &comp);
    void assign(double R, double Ima);
    void printComplex();
    Complex add(Complex n1);
    Complex subtract(Complex n1);
    Complex multiply(Complex n1);
    Complex division(Complex n1);
    void assignReal(double R);
    void assignImage(double Ima);
    Complex operator + (const Complex &) const;
    Complex operator - (const Complex &) const;
    Complex operator - () const;
    Complex operator * (const Complex &) const;
    Complex operator / (const Complex &) const;
    friend void printMeg(const Complex &, const Complex &, const char &);
    double Complex_abs() const;
    void setComplexNumber(const double &real, const double &image);
    friend void printComplex(const Complex &);
    friend ostream& operator <<(ostream &out, const Complex &c1);
};
#endif 
