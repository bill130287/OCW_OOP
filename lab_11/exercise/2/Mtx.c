#include <iostream>
#include "Mtx.h"
using namespace std;
//int *a;
const int& FullMatrix::operator ()(int i ,int j) const
{
    if (i >= dim || j >= dim || i < 0 || j < 0)
    {
        int *a;
        return *a; 
    }       
    else
        return matrix[i][j]; 
}

void FullMatrix::showMatrix() const
{
    for(int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            cout << matrix[i][j] << ' '; 
        } 
        cout << endl;
    } 
}

FullMatrix::~FullMatrix()
{
    for (int i=0; i<dim; i++)
    {
        delete [] matrix[i]; 
    } 
    delete [] matrix;
}

const int& SymmetricMatrix::operator ()(int i ,int j) const
{
    if (i >= dim || j >= dim || i < 0 || j < 0)
    {
        int *a;
        return *a; 
    }       
    else
        return matrix[i][j]; 
}

void SymmetricMatrix::showMatrix() const
{
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            if (i >= j)
                cout << matrix[i][j] << ' '; 
            else 
                cout << matrix[j][i] << ' ';
        } 
        cout << endl;
    } 
}

int& SymmetricMatrix::GetMatrixOne(const int i, const int j)
{
    if (i >= dim || j >= dim || i < 0 || j < 0)
        cout << "index is out of range" << endl;
    else if (i >= j) 
        return matrix[i][j];
    else 
        return matrix[j][i]; 
}

SymmetricMatrix::~SymmetricMatrix()
{
    for (int i=0; i<dim; i++)
       delete [] matrix[i];
    delete [] matrix; 
}

int& LowTriMatrix::operator ()(int i, int j)
{
    /*if (i >= dim || j >= dim || i < 0 || j < 0)
    {
        int *a;
        return *a; 
    }
    else if (i>=j) 
        return GetMatrixOne(i, j);
    else 
        return GetMatrixOne(j, i);
    */
    //v1
    int *b;
    if (i >=dim || j >= dim || i < 0 || j < 0)
    {
        //int *a;
        cout << "index is out of range" << endl;
        return *b; 
    } 
    else if (i >= j)
    { 
        //return SymmetricMatrix::GetMatrixOne(i, j);
        SymmetricMatrix::operator() (i, j);
    }
    else
    { 
        //int *a;
        cout << "can not set this index for LowTrimatrix" << endl;
        return *b; 
    }
    //v2
    /*if (i >= j)
        return SymmetricMatrix::GetMatrixOne(i,j);
    else
    {
        int *a;
        return *a; 
    }*/

}

/*const int& LowTriMatrix::operator ()(int i, int j) const
{
    //
    //int *a;
    if (i >=dim || j >= dim || i < 0 || j < 0)
    {
        cout << "index is out of range" << endl;
        return *a; 
    } 
    else if (i >= j)
        return SymmetricMatrix::GetMatrixOne(i, j);
    else
    { 
        cout << "can not set this index for LorTriMatrix" << endl;
        *a = 0
        return *a; 
    }//

    return LowTriMatrix::operator ()(i, j);
 
}*/

void LowTriMatrix::showMatrix() const
{
    //cout << "Good" << endl;
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            if (i >= j)
            { 
                //cout <<  SymmetricMatrix::GetMatrixOne(i,j) << ' ';
                SymmetricMatrix::PrintMatrixOne(i, j);
                cout << ' ';
            }
            else 
                cout << 0 << ' '; 
        } 
        cout << endl;
    } 
}

int& UpperTriMatrix::operator ()(int i, int j)
{
    int *c;
    if (i >=dim || j >= dim || i < 0 || j < 0)
    {
        //cout << "index is out of range" << endl;
        return *c; 
    } 
    else if (j >= i)
    {   
        return SymmetricMatrix::operator ()(j, i); 
    }//return SymmetricMatrix::GetMatrixOne(j, i);
    else
    { 
        //cout << "can not set this index for UpperTrimatrix" << endl;
        return *c; 
    }

}

/*const int& UpperTriMatrix::operator ()(int i, int j) const
{
    
    int *a;
    if (i >=dim || j >= dim || i < 0 || j < 0)
    {
        cout << "index is out of range" << endl;
        return *a; 
    } 
    else if (j >= i)
        return SymmetricMatrix::GetMatrixOne(j, i);
    else
    { 
        cout << "can not set this index for UpperTriMatrix" << endl;
        //*a = 0
        return *a; 
    }

    return UpperTriMatrix::operator ()(i, j);
 
}*/

void UpperTriMatrix::showMatrix() const
{
    //cout << "UpperTriMatrix showMatrix()" << endl;
    for (int i=0; i<dim; i++)
    {
        //cout << "i: " << i << endl;
        for (int j=0; j<dim; j++)
        {
            //cout << "j: " << j << endl;
            if (j >= i)
            { 
                SymmetricMatrix::PrintMatrixOne(j, i);
                cout << ' ';
                //cout << SymmetricMatrix::GetMatrixOne(j,i) << ' ';
            }
            else 
                cout << 0 << ' ';
        } 
        cout << endl;
    } 
}

