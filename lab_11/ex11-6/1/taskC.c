#include <iostream>
#include <iomanip>
#include <cmath>
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
    virtual double area() = 0;
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
    Triangle() {vertices = new Point2D [3];}
    Triangle(Point2D *vec);
    Triangle(Point2D *vec, int Color);
    ~Triangle() {delete [] vertices;}
    void draw();
    double area();
};

Triangle::Triangle(Point2D *vec)
{
    vertices = new Point2D [3];
    for (int i=0; i<3; i++)
    {
        vertices[i].setPoint2D(vec[i].GetX(), vec[i].GetY()); 
    }

    color = 0;
}

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

double Triangle::area()
{
    Point2D vecA, vecB;

    vecA.setPoint2D(vertices[1].GetX()-vertices[0].GetX(), vertices[1].GetY()-vertices[0].GetY());
    //vecA.SetY(vertices[1].GetY()-vertices[0].GetY());
    vecB.setPoint2D(vertices[2].GetX()-vertices[0].GetX(), vertices[2].GetY()-vertices[0].GetY());
    //vecB.SetY(vertices[2].GetY()-vertices[0].GetY());
    
    double A;
    
    A = double(abs(vecA.GetX()*vecB.GetY()-vecA.GetY()*vecB.GetX()))/2;
    return A;
}

class Circle: public Shape
{
private:
    Point2D center;
    double radius;
public:
 // constructor of Circle.
    Circle(Point2D pt, int R, int Color) {center.setPoint2D(pt.GetX(), pt.GetY()); radius = R; color = Color;}
    Circle(Point2D pt, int R) {center.setPoint2D(pt.GetX(), pt.GetY()); radius = R; color = 0;}
    void draw();
    bool is_closed() {return true;}
    double area();
};

void Circle::draw() 
{
    cout << "Color: " << color << endl;
    cout << "Center: " << center.GetX() << ',' << center.GetY() << endl;
    cout << std::fixed << std::setprecision(1) << "Radius: " << radius << endl;
}

double Circle::area()
{
    return radius * radius * M_PI; 
}

class Rectangle: public Shape
{
private:
    Point2D *vertices;
public:
    Rectangle() {vertices = new Point2D [4]; color = 0;}
    Rectangle(Point2D *vec);
    void draw();
    bool is_closed() {return true;} 
    double area();
};

Rectangle::Rectangle(Point2D *vec)
{
    vertices = new Point2D [4];
    
    for (int i=0; i<4; i++)
    {
        vertices[i].setPoint2D(vec[i].GetX(), vec[i].GetY());
    } 

    color = 0;
}

void Rectangle::draw()
{
    for (int i=0; i<4; i++)
    {
        vertices[i].display();
        cout << endl; 
    } 
}

double Rectangle::area()
{
    Point2D vecA, vecB;

    vecA.setPoint2D(vertices[1].GetX()-vertices[0].GetX(), vertices[1].GetY()-vertices[0].GetY());
    //vecA.SetY(vertices[1].GetY()-vertices[0].GetY());
    vecB.setPoint2D(vertices[2].GetX()-vertices[0].GetX(), vertices[2].GetY()-vertices[0].GetY());
    //vecB.SetY(vertices[2].GetY()-vertices[0].GetY());
    
    double A;
    
    A = double(abs(vecA.GetX()*vecB.GetY()-vecA.GetY()*vecB.GetX()));
    return A;

}

int main()
{
    Point2D pt(3,4);
    Circle cir(pt, 5);
    Point2D *vec = new Point2D [3];
    vec[0].setPoint2D(1,1); 
    vec[1].setPoint2D(1,6);
    vec[2].setPoint2D(8,1);

    Triangle tri(vec);
    delete []vec;
    vec = new Point2D [4];
    vec[0].setPoint2D(1,1); 
    vec[1].setPoint2D(6,1); 
    vec[2].setPoint2D(6,6); vec[3].setPoint2D(1,6);

    Rectangle rect(vec);
    delete [] vec;
    Shape *collection[3];
    collection[0] = &cir;
    collection[1] = &tri;
    collection[2] = &rect;

    cout << "Area of Circle: " << collection[0]->area() << endl;
    cout << "Area of Triangle: " << collection[1]->area() << endl;
    cout << "Area of Rectangle: " << collection[2]->area() << endl;
    return 0;
}

