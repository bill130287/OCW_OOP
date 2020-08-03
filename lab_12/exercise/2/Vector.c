#include <iostream>
#include "Vector.h"
#include "Point2D.h"
using namespace std;

template <class T>
Vector<T>::Vector(int n, int data)
{
    len = n;
    vec = new T [n];
    
    for (int i=0; i<n; i++)
    {
        vec[i] = T(data); 
    } 
}

template <class T>
Vector<T>::Vector(int n, T *A_data)
{
    len = n;
    vec = new T [n];
    
    for (int i=0; i<n; i++)
    {
        vec[i] = A_data[i]; 
    } 
}

template <>
Vector<Point2D>::Vector(int n, int data)
{
    len = n;
    vec = new Point2D [n];
    
    for (int i=0; i<n; i++)
    {
        vec[i].SetPoint2D(data, data); 
    } 
}

template <>
Vector<Point2D>::Vector(int n, Point2D *A_data)
{
    len = n;
    vec = new Point2D [n];
    
    for (int i=0; i<n; i++)
    {
        vec[i].SetPoint2D(A_data[i].GetX(), A_data[i].GetY()); 
    }    
}

template <class T>
T Vector<T>::Getvec_index(int i) const
{
    return vec[i]; 
}

template <class T>
int Vector<T>::Getlen() const
{
    return len; 
}

template <class T>
void Vector<T>::display() const
{
    for (int i=0; i<len; i++)
    {
       cout << vec[i] << ' '; 
    }
    cout << endl;
}

template <>
void Vector<Point2D>::display() const
{
    for (int i=0; i<len; i++)
    {
         vec[i].displayPoint2D();
         cout << ' ';
    }

    cout << endl; 
}

template <class T>
void Vector<T>::operator +=(Vector &v1)
{
    for (int i=0; i<len; i++)
    {
        vec[i] += v1.Getvec_index(i);
    } 

    //return *this;
}

template <>
void Vector<Point2D>::operator +=(Vector &v1)
{
    for (int i=0; i<len; i++)
    {
        vec[i].SetPoint2D(vec[i].GetX() + v1.Getvec_index(i).GetX(), vec[i].GetY() + v1.Getvec_index(i).GetY());
    }
}

template <class S>
S dot(const Vector<S> &v1, const Vector<S> &v2)
{
    S dot_v = S(0);
    for (int i=0; i<v1.Getlen(); i++)
    {
        dot_v += v1.Getvec_index(i) * v2.Getvec_index(i);
    }
    
    return dot_v;
}

template <>
Point2D dot(const Vector<Point2D> &v1, const Vector<Point2D> &v2)
{
    int x1 = 0, y1 = 0;
    if (v1.Getlen() != v2.Getlen())
    {
        cerr << "len of two Point2D is different.";  
    }

    for (int i=0; i<v2.Getlen(); i++)
    {
        x1 += v1.Getvec_index(i).GetX() * v2.Getvec_index(i).GetX();
        y1 += v1.Getvec_index(i).GetY() * v2.Getvec_index(i).GetY(); 
    } 

    return Point2D(x1, y1);
}
template class Vector<double>;
template double dot(const Vector<double> &, const Vector<double> &); //If no these lines, compiler will say undefine reference to ....

