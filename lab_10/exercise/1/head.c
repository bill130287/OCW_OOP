#include <iostream>
#include <cmath>
#include "head.h"
//#define M_PI 3.1415926 //redefine
using namespace std;

void Point2D::display() const
{
    cout << x << ',' << y; 
}

Circle::Circle(int x, int y, int r, int Color):Shape(Color)
{
    center.SetX(x);
    center.SetY(y);
    radius = r; 
    //color = Color;
}

void Circle::draw() const
{
    cout << "Center: ";
    center.display();
    cout << endl;
    cout << "Radius: " << radius << endl; 
}

double Circle::area() const
{
    return double(radius*radius)*M_PI; 
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int Color):Shape(Color)
{
    vertices = new Point2D [3];
    
    vertices[0].SetX(x1);
    vertices[0].SetY(y1);
    vertices[1].SetX(x2);
    vertices[1].SetY(y2);
    vertices[2].SetX(x3);
    vertices[2].SetY(y3); 

    //color = Color;
}

void Triangle::draw() const
{
    cout << "Vertices:" << endl;
    
    for (int i=0; i<3; i++)
    {
        vertices[i].display();
        cout << endl;
    }
}

double Triangle::area() const
{
    Point2D vecA, vecB;

    vecA.SetX(vertices[1].GetX()-vertices[0].GetX());
    vecA.SetY(vertices[1].GetY()-vertices[0].GetY());
    vecB.SetX(vertices[2].GetX()-vertices[0].GetX());
    vecB.SetY(vertices[2].GetY()-vertices[0].GetY());
    
    double A;
    
    A = double(abs(vecA.GetX()*vecB.GetY()-vecA.GetY()*vecB.GetX()))/2;
    return A;
}


