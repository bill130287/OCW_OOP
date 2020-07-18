// Point4D.h
#ifndef POINT4D_H
#define POINT4D_H
#include "Point2D.h"
class Point4D : public Point2D
{
private:
 int *z;
 int *t;

public:
    Point4D(int x1 = 0, int y1 = 0, int z1 = 0, int t1 = 0):Point2D(x1, y1){z = new int (z1); t = new int(t1);}
    void display() const;
    void operator = (const Point2D &pt);
};

void Point4D::display() const
{
    Point2D::display();
    cout << ',' << *z << "," << *t;
}

void Point4D::operator = (const Point2D &pt)
{
    Point4D test(pt.GetX(), pt.GetY(), *(this->z), *(this->t));
    *this = test; 
}
#endif 
