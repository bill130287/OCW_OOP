// Matrix.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using std::cout;
#include "Matrix.h"
// Member-function definitions for class Matrix. 
void Matrix::assignDimension(int n)
{
    if (n <= 0)
    {
        cout << "Matrix dimension must >= 0" << std::endl;
        exit(1); 
    }

    mat = new int *[n];
    for (int row=0; row<n; row++)
    {
        mat[row] = new int [n]; 
    }
    size = n; 
    //cout << "assignDimension is OK!" << std::endl;
    //cout << "size: " << size << std::endl;
}
void Matrix::assignElements()
{
    //srand((unsigned)time(NULL));
    //cout << "srand is OK!" << std::endl;
    //cout << "size: " << size << std::endl;
    srand(time(NULL));
    Sleep(1000);
    for (int i=0; i<size; i++)
    {
        //cout << "row " << i << " is  starting" << std::endl;
        //srand(time(NULL));
        for (int j=0; j<size; j++)
        {
            //srand(time(NULL));
            mat[i][j] = rand() % 11;
            //cout << i << j << " = " << mat[i][j] << std::endl;  
        } 
        //cout << "row " << i << " is  finishing" << std::endl;

    } 
    //cout << "assignElements is OK!" << std::endl;
}
void Matrix::printMatrix()
{
    cout << "[";
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
             cout << mat[i][j];
             if (j != size-1)
                 cout << " ";
        }
        if (i == size-1) cout << "]"; 
        cout << "; ";
    }
    //cout << "]"; 
    //cout << std::endl;
}
void Matrix::assignMatrix(Matrix matrix)
{
    Matrix::assignDimension(matrix.size);
    //mat = new int *[matrix.size];
    //size = matrix.size;
    
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            mat[i][j] = matrix.mat[i][j]; 
        } 
    } 
}
void Matrix::transposeMatrix()
{
    int tmp,col = 0;

    for (int i=0; i<size; i++)
    {
        for (int j=col; j<size; j++)
        {
            tmp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = tmp; 
        } 
        col += 1;
    } 
}
Matrix Matrix::addMatrix(Matrix matrix)
{
    Matrix result;
    result.assignDimension(matrix.size);
    //result.mat = new int *[size];
    //result.size = size;
    for (int i=0; i<size; i++)
    {   
        for (int j=0; j<size; j++)
        {
            result.mat[i][j] = mat[i][j] + matrix.mat[i][j]; 
        }
    }

    return result;
}
Matrix Matrix::subtractMatrix(Matrix matrix)
{
    Matrix result;
    result.assignDimension(matrix.size);
    //result.mat = new int *[size];
    //result.size = size;
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            result.mat[i][j] = mat[i][j] - matrix.mat[i][j];
        } 
    } 
    
    return result;
}
Matrix Matrix::multiplyMatrix(Matrix matrix)
{
    Matrix result;
    int sum = 0;
    result.assignDimension(matrix.size);
    //result.mat = new int *[size];
    //result.size = size;
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
             for (int k=0; k<size; k++)
             {
                    sum += mat[i][k] * matrix.mat[k][j]; 
             }
             result.mat[i][j] = sum;
             sum = 0;
        } 
    } 

    return result;
}

