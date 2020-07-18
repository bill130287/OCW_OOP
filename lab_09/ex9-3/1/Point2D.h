// Point2D.h
#ifndef POINT2D_H
#define POINT2D_H
using namespace std;

class Point2D
{
private:
 int *x;
 int *y;

public:
    Point2D(int x1 = 0, int y1 = 0){ x = new int(x1); y = new int(y1);}
    void display() const{cout<< *x << "," << *y ; }
    int GetX() const {return *x;}
    int GetY() const {return *y;}
};
#endif
