#include <iostream>
#include "Vector.h"
#include "Point2D.h"
using namespace std;

template <class T = Point2D>
void rand1D(Point2D *vec, int n)
{
    const int bucket = RAND_MAX / n;
    int x1, y1;

    for (int i=0; i<n; i++)
    {
        do
        {
            x1 = rand() / bucket; 
        }while (x1 >= n);

        do
        {
            y1 = rand() / bucket; 
        }while (y1 >= n);

        vec[i].SetPoint2D(x1, y1); 
    }
     
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    Vector<double> dvec(n,1);

    double *b = new double[n];
    for (int i=0;i<n;i++) b[i] = i;
    Vector<double> dvec2(n,b);

    cout << "dvec = "; dvec.display();
    cout << "dvec2 = "; dvec2.display();
    dvec2 += dvec;
    cout << "new dvec = "; dvec2.display();

    double c = dot(dvec, dvec2);
    cout << "dot(dvec, dvec2) = " << c << endl << endl;
    
    srand(128);
    Point2D *v = new Point2D[n];
    rand1D<Point2D>(v,n); //0~9
    Vector<Point2D> vp1(n,1);
    Vector<Point2D> vp2(n,v);

    cout << "vp1 = "; vp1.display();
    cout << "vp2 = "; vp2.display();
    vp2 += vp1; 
    cout << "new vp2 = "; vp2.display();

    Point2D d = dot(vp1, vp2);
    cout << "dot(vp1, vp2) = " << d << endl; 
    return 0;
}
