#ifndef MTX_H
#define MTX_H

#include <iostream>
#define OutOfRange 0x0a
using namespace std;

class Mtx
{
protected:
    int dim;
public:
    virtual int &operator()(int i, int j) =0;
    virtual const int &operator() (int i, int j) const = 0;
    virtual void showMatrix() const = 0;
    virtual ~Mtx(){}
};

class FullMatrix: public Mtx
{
private:
    int **matrix;
public:
    FullMatrix(int n)
    {
        dim = n;
        matrix = new int *[dim];
        for (int i=0;i<dim;i++) matrix[i] = new int [dim];
        for (int i=0;i<dim;i++)
            for (int j=0;j<dim;j++) matrix[i][j] = 0;
    }
    int &operator()(int i, int j)
    {
        // you may provide boundary checking
        if (i >= dim || j >= dim || i < 0 || j < 0)
        {
            int *a;
            return *a; 
        }
        else
            return matrix[i][j];
    }
    const int& operator ()(int i, int j) const;
    void showMatrix() const;
    ~FullMatrix();
};

class SymmetricMatrix: public Mtx
{
private:
    int **matrix;
public:
    SymmetricMatrix(int n)
    {
        dim = n;
        matrix = new int *[dim];
        for (int i=0;i<dim;i++) matrix[i] = new int [i+1];
        for (int i=0;i<dim;i++)
            for (int j=0;j<=i;j++) matrix[i][j] = 0;
    }
    int &operator()(int i,int j)
    {
        // you need provide boundary checking
        if (i >= dim || j >= dim || i < 0 || j < 0)
        {
            int *a;
            return *a; 
        }
        else if (i>=j) 
            return matrix[i][j];
        else 
            return matrix[j][i];
    }
    const int& operator ()(int i, int j) const;
    virtual void showMatrix() const;
    int& GetMatrixOne(int i, int j);
    void PrintMatrixOne(const int i, const int j) const{cout << matrix[i][j];}
    ~SymmetricMatrix();
};

class LowTriMatrix: public SymmetricMatrix
{
public:
    LowTriMatrix(int n): SymmetricMatrix(n){}
    int &operator ()(int i, int j);
    //const int& operator ()(int i, int j) const;
    void showMatrix() const;
    ~LowTriMatrix(){}
};

class UpperTriMatrix : public SymmetricMatrix
{
public:
    UpperTriMatrix(int n):SymmetricMatrix(n){}
    int& operator ()(int i, int j);
    //const int& operator ()(int i, int j) const;
    void showMatrix() const;
    ~UpperTriMatrix(){}
};
#endif
