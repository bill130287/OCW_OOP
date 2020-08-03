#include <iostream>
#include <cstdlib>
#include "Point2D.h"
using namespace std;

Point2D::Point2D(int x1, int y1)
{
    x = x1;
    y = y1; 
}

void Point2D::SetPoint2D(int x1, int y1)
{
    x = x1;
    y = y1; 
}

void Point2D::displayPoint2D() const
{
    cout << '(' << x << ',' << y << ')';
}

int Point2D::GetX()
{
    return x; 
}

int Point2D::GetY()
{
    return y; 
}

ostream& operator <<(ostream &out, Point2D &vertex)
{
    out << '(' << vertex.GetX() << ',' << vertex.GetY() << ") ";
    return out; 
}
