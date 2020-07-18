#include <iostream>
#include "Point2D.h"
#include "Point4D.h"
using std::cout; using std::endl;
int main()
{
 /*int *a;
 int x = 2;
 *a = x;
 cout << *a << endl;*/
 Point2D pt1(1,2);
 //cout << "2" << endl;
 Point2D pt2(3,4);
 //cout << "hi" << endl;
 pt1.display(); cout << endl;
 pt2.display(); cout << endl;

 pt2 = pt1;
 pt2.display(); cout << endl;

 Point4D pt4(5,6,7,8);
 pt4.display(); cout << endl;

 pt2 = pt4;
 pt2.display(); cout << endl;

 pt4 = pt1;
 pt4.display(); cout << endl; //pt4 could be (1,2,7,8) or (1,2,0,0)
 return 0;
} 
