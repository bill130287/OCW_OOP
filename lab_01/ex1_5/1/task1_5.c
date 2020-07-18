// ex1-1.cpp
// include file
#include <iostream>
#include "lab1_1.h"
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;
using namespace Complex;

void ReadTextFile(char *, Cplex &, Cplex &);
Cplex ComplexOperation(const Cplex, const Cplex, char);
void PrintComplex(char *, Cplex *);

int main(int argc, char *argv[])
{
    Cplex a, b; // use struct named Cplex under namespace Complex
    ReadTextFile(argv[1], a, b); // process text file
    Cplex results[4]; // store the results of diff. operation
    results[0] = ComplexOperation(a, b, '+');
    results[1] = ComplexOperation(a, b, '-');
    results[2] = ComplexOperation(a, b, '*');
    results[3] = ComplexOperation(a, b, '/');
    PrintComplex(argv[2], results); // print the results on file.
    
    return 0;
}

void ReadTextFile(char *argv, Cplex &a, Cplex &b)
{
    ifstream in_file(argv); //or next row: in_file.open(argv);
    //ifstream in_file2(argv);
    if (in_file.fail())
    {
        cout << "Cannot open the file. " << argv << endl;
        exit(1);
    }
    
    char sign;
    int str_size;
    string textline;
    
    in_file >> a.real >> a.image; // getline(in_file, textline, '\n'))
    //cout << re << " " << im << endl;
    in_file.close();

    in_file.open(argv);
    if (in_file.fail())
    {
        cout << "Cannot open the file." << argv << endl; 
        exit(1);
    }
    getline(in_file, textline);
    in_file >> b.real >> b.image;
    //getline(in_file2, textline);
    //in_file2 >> re >> im;
    //cout << re << " " << im << endl;
    in_file.close();    
}

Cplex ComplexOperation(const Cplex a, const Cplex b, char op)
{
    Cplex result;
    switch (op)
    { 
        case '+':
            result.real = a.real + b.real;
            result.image = a.image + b.image;
            break;
        case '-':
            result.real = a.real - b.real;
            result.image = a.image - b.image;
            break;
        case '*':
            result.real = a.real * b.real - a.image * b.image;
            result.image = a.real * b.image + a.image * b.real;
            break;
        case '/':
            result.real = (a.real*b.real + a.image*b.image) / (b.real*b.real + b.image*b.image);
            result.image = (a.image*b.real - a.real*b.image) / (b.real*b.real + b.image*b.image);
            break;
        default:
            cout << "No" << op << "operation" << endl;
            break;
    }
    return result; 
}

void PrintComplex(char *argv, Cplex *results)
{
    ofstream outFile(argv);
    outFile.setf(ios::fixed);
    outFile.precision(3);
    int size;
    size = sizeof(results);
    //cout << "size resulsts is " << sizeof(results) << endl;
    for (int i=0; i<size; i++)
    {   
        if (results[i].image >= 0)
        {
            outFile << results[i].real << "+" << results[i].image << "i" << endl; 
        }
        else
        {
            outFile << results[i].real << results[i].image << "i" << endl; 
        }
    }
    
    outFile.close();
}
