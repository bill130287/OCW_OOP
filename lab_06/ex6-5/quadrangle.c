#include <iostream>
#include <iomanip>
#include "quadrangle.h"
#include <cmath>
using namespace std;
Vex quadrangle::origin;

Vex quadrangle::vertex(int x1, int y1)
{
    Vex result;
    result.x = x1;
    result.y = y1;
    return result; 
}

quadrangle::quadrangle()
{
    vertices = new Vex [4];
    for (int i=0; i<4; i++)
    {
        vertices[i].x = 0;
        vertices[i].y = 0; 
    } 
}

quadrangle::quadrangle(Vex vertex1, Vex vertex2, Vex vertex3, Vex vertex4)
{ 
     vertices = new Vex [4];
     vertices[0] = vertex1;
     vertices[1] = vertex2;
     vertices[2] = vertex3;
     vertices[3] = vertex4;
}

quadrangle::quadrangle(Vex vertex1, Vex vertex2)
{
    vertices = new Vex [4]; 

    vertices[0] = vertex1;
    vertices[1].x = vertex2.x;
    vertices[1].y = vertex1.y;
    vertices[2] = vertex2;
    vertices[3].x = vertex1.x;
    vertices[3].y = vertex2.y;
}

void quadrangle::draw()
{
    for (int i=0; i<4; i++)
    {
        cout << "v" << i+1 << " (" << vertices[i].x << ",";
        cout << vertices[i].y << left << setw(5) <<")"; 
    } 
    int vX1 = 0, vY1 = 0, vX2 = 0, vY2 = 0;
    int vX3 = vertices[3].x - vertices[0].x;
    int vY3 = vertices[3].y - vertices[0].y;
    int inndot = 0;
    bool rectF = 0;
    for (int i=0; i<2; i++)
    {
        vX1 = vertices[i+1].x - vertices[i].x;
        vY1 = vertices[i+1].y - vertices[i].y;
        vX2 = vertices[i+2].x - vertices[i+1].x;
        vY2 = vertices[i+2].y - vertices[i+1].y;
        inndot = vX1*vX2 + vY1*vY2;
        if (inndot)
        {
            rectF = 0;
            break; 
        } 

        else
        {
            rectF = 1; 
        }
    }

    inndot = vX3*vX2 + vY3*vY2;
    if (inndot) rectF = 0;
    //cout << "draw rectF: " << rectF;
    
    if (rectF)
    {
        cout << "area: " <<  abs(vX3*vY2 - vX2*vY3); 
    } 

}

void quadrangle::move(Vex move1)
{
    int offset_x = 0, offset_y = 0;
    offset_x = move1.x - vertices[0].x;
    offset_y = move1.y - vertices[0].y;
    for (int i=0; i<4; i++)
    {
        vertices[i].x = vertices[i].x + offset_x;
        vertices[i].y = vertices[i].y + offset_y; 
    } 

    double distance = sqrt(pow(move1.x-quadrangle::origin.x,2)+pow(move1.y-quadrangle::origin.y,2));
    cout << "Distance: " << distance << endl;
}
