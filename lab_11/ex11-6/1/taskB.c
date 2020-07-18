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
    void setPoint2D(int x1, int y1) {*x = x1; *y = y1;}
    int GetX() const {return *x;}
    int GetY() const {return *y;}
    void display() const {cout << *x << ',' << *y;}
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

class Polygon: public Shape
{
public:
 bool is_closed() {return true;}
};

class Triangle: public Polygon
{
private:
    Point2D *vertices;
public:
    // constructor for Triangle
    Triangle () {vertices = new Point2D [3];}
    Triangle (Point2D *vec, int Color);
    ~Triangle() {delete [] vertices;}
    void draw();
}; 

Triangle::Triangle(Point2D *vec, int Color)
{
    vertices = new Point2D [3];
    for (int i=0; i<3; i++)
    {
        vertices[i].setPoint2D(vec[i].GetX(), vec[i].GetY()); 
    } 

    color = Color;
}

void Triangle::draw()
{
    cout << "Color: " << color << endl;
    cout << "Vertices: " << endl;
    for (int i=0; i<3; i++)
    {
       vertices[i].display();
       cout << endl;
    } 
}
/*class Circle: public Shape
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
}*/

int main()
{
    Point2D *vec = new Point2D[3];
    vec[0].setPoint2D(1,1);
    vec[1].setPoint2D(6,1);
    vec[2].setPoint2D(1,8);    
    Triangle t(vec,255);
    delete []vec;

    t.draw();
    return 0;
}

