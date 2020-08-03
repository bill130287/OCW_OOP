#include <iostream>
#include <iomanip>
using std::cout; using std::endl; 
class Point2D
{
private:
 int *x;
 int *y;
public:
 Point2D(){x = new int (0);y=new int (0); /*cout << "New X and Y" << endl;*/}
 Point2D(int x1, int y1) {x = new int (x1); y = new int (y1);}
 void SetPoint(int x1, int y1) {*x = x1; *y = y1;}
 int GetX() const {return *x;}
 int GetY() const {return *y;}
 virtual ~Point2D(){delete x; delete y; /*cout << "Delete X and Y" << endl;*/}
};

class Shape
{
protected:
 int color;
public:
 virtual void draw() = 0;
 virtual bool is_closed() = 0;
 virtual ~Shape(){}
}; 

class Circle: public Shape
{
private:
 Point2D center;
 double radius;
public:
 // constructor of Circle.
 Circle(Point2D pt, int R, int Color) {center.SetPoint(pt.GetX(), pt.GetY()); radius = R; color = Color;}
 void draw();
 bool is_closed() {return true;}
}; 

void Circle::draw() 
{
    cout << "Color: " << color << endl;
    cout << "Center: " << center.GetX() << ',' << center.GetY() << endl;
    cout << std::fixed << std::setprecision(1) << "Radius: " << radius << endl;
}

int main()
{
 Point2D pt(3,4);
 Circle c(pt,5,255);
 c.draw();

 return 0;
}

