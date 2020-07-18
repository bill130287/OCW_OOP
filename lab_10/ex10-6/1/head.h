#ifndef HEAD_H
#define HEAD_H
#include <iomanip>
using namespace std;

class Shape
{
protected:
 int color;
public:
 Shape(int Color=0) {color = Color;}
}; 
class Point2D
{
private:
 int x;
 int y;
public:
 Point2D(){x = 0;y = 0;}
 Point2D(int x1, int y1){x = x1; y = y1; }
 void display() const;
 int GetX() const {return x;}
 int GetY() const {return y;}
 void SetX(int x1) {x = x1;}
 void SetY(int y1) {y = y1;}
 void Set(int x1, int y1) {x = x1; y = y1;}
 //...
};

class Circle:public virtual Shape
{
private:
 Point2D center;
 double radius;
public:
 Circle(int x=0, int y=0, int r=0, int Color=0);//:Shape(Color);
 void draw() const;
 double area() const;
 //
};

class Triangle:public virtual Shape
{
private:
 Point2D *vertices;
public:
 // ...
 Triangle(int x1=0, int y1=0, int x2=0, int y2=0, int x3=0, int y3=0, int Color=0);//:Shape(Color);
 ~Triangle(){delete [] vertices;}
 void draw() const;
 double area() const;
};

class Circle_in_Triangle: public Circle, public Triangle
{
public:
 // 
 Circle_in_Triangle(Point2D p, int r, int Color, Point2D *vec):Shape(Color), Circle(p.GetX(), p.GetY(), r, Color),
                    Triangle(vec[0].GetX(), vec[0].GetY(), vec[1].GetX(), vec[1].GetY(), vec[2].GetX(), vec[2].GetY(), Color){}
 double area() const
 {
    return Triangle::area()-Circle::area(); 
 }
 void draw()
 {
    cout << "Circle's color: " << Circle::color << endl;
    cout << "Triangle's color: " << Triangle::color << endl;
    Circle::draw();
    Triangle::draw();
    cout << "Area of Circle: " << fixed << setprecision(2) << Circle::area() << endl;
    cout << "Area of Triangle: " << fixed << setprecision(2) << Triangle::area() << endl;
    cout << "Area of Circle_in_Triangle: " << fixed << setprecision(2) << area() << endl; 
 }
};

#endif

