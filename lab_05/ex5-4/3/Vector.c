#include <iostream>
#include "vector.h"
using std::cout;
using std::endl;
Vec::Vec(){;}

Vec::Vec(int *array1, int dim1)
{
    dim = dim1;
    Arr = new int [dim];
    for (int i=0; i<dim; i++)
    {
         Arr[i] = array1[i];
    } 
}

void Vec::assign(int *array1, int dim1)
{
    dim = dim1;
    Arr = new int [dim];
    for (int i=0; i<dim; i++)
    {
        Arr[i] =  array1[i];
    } 
}

void Vec::sort()
{
    int key,j;
    for (int i=1; i<dim; i++)
    {
        key = Arr[i];
        j = i-1;
        while (j>=0 && Arr[j] > key)
        {
             Arr[j+1] = Arr[j];
             j = j-1;
        }
        Arr[j+1] = key; 
    } 
}

void Vec::printVec()
{
    for (int i=0; i<dim; i++)
    {
        cout << " " << Arr[i];
    }
    cout << endl;  
}

bool Vec::isEqual(Vec vec1)
{
    if (dim != vec1.dim) return 0;
    
    bool Equal = 0;
    for (int i=0; i<dim; i++)
    {
        if (Arr[i] == vec1.Arr[i]) Equal = 1;
        
        else
        {
            Equal = 0;
            break;
        }    
    } 
    return Equal;
}

void Vec::unionSet(Vec vec1, Vec vec2)
{
    dim = vec1.dim + vec2.dim;
    Arr = new int [dim];
    int seg = vec1.dim;
    //cout << "vec1.dim: " << vec1.dim << " ";
    //cout << "vec2.dim: " << vec2.dim << endl;
    //cout << "UnionSet dimension: " << dim << endl;
    //cout << "UnionSet seg: " << seg << endl;
    for (int i=0; i<dim; i++)
    {
       if (i < seg)
       {
            Arr[i] = vec1.Arr[i]; 
       } 

       else
       {
            Arr[i] = vec2.Arr[i-vec1.dim]; 
       }
    } 
}

int Vec::min()
{
    int min = Arr[0];
    
    for (int i=1; i<dim; i++)
    {
        if (Arr[i] < min)
            min = Arr[i];
    } 

    return min;
}

int Vec::max()
{
    int max = Arr[0];

    for (int i=1; i<dim; i++)
    {
        if (Arr[i] > max)
            max = Arr[i]; 
    }

    return max; 
}

bool Vec::find(int target)
{
    bool istarget = 0;
    
    for (int i=0; i<dim; i++)
    {
        if (Arr[i] == target)
        { 
            istarget = 1;
            break;
        } 
    } 

    return istarget;
}

Vec Vec::inpendetSet()
{
    int dim1 = 0;
    int key = Arr[0];
    dim1 += 1;

    for (int i=1; i<dim; i++)
    {
        if (key != Arr[i])
        {
            key = Arr[i];
            dim1 += 1;
        }
    }
    int *array1 = new int [dim1];
    int result_D = dim1;
    dim1 -= 1;
    key = Arr[dim-1];
    array1[dim1] = Arr[dim-1];
    dim1 -= 1;
    for (int j=dim-2; j>=0; j--)
    {
        if (key != Arr[j])
        {
            key = Arr[j];
            array1[dim1] = Arr[j];
            dim1--; 
        }
    }
    
    Vec result(array1, result_D);
    return result;  
}
