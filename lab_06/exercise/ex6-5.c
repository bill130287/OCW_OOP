// Ex6-1.cpp
#include <iostream>
#include "quadrangle.h"
using namespace std;
//Vex quadrangle::origin;
int main()
{ 
    quadrangle q1(quadrangle::vertex(0,0),
    quadrangle::vertex(3,2),
    quadrangle::vertex(10,7),
    quadrangle::vertex(8,10));
    quadrangle q2(quadrangle::vertex(3,6), quadrangle::vertex(10,9));
    cout << "q1 information" << endl;
    q1.draw();
    cout << endl;
    cout << "q2 information" << endl;
    q2.draw();
    cout << endl;
    cout << "q1 move to (5,5) " << endl;
    q1.move(quadrangle::vertex(5,5));
    cout << "q1 information" << endl;
    q1.draw();
    cout << endl;
    quadrangle::origin = quadrangle::vertex(-5,3);
    cout << "q2 move to (-1,2) " << endl;
    q2.move(quadrangle::vertex(-1,2));
    cout << "q2 information" << endl;
    q2.draw();
    cout << endl;
    return 0;
} // end main
