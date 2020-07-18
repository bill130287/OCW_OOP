#include <iostream>
#ifndef QUADRANGLE_H
#define QUADRANGLE_H
//Vex vertex(int, int);
class Vex
{ 
private:
    friend class quadrangle;
    //friend Vex vertex(int x1, int y1);
    int x;
    int y;
public:
    Vex vertex(int x1, int y1)
    {
        x = x1;
        y = y1;
        return *this;
    };
    Vex(){x = 0; y = 0;};
    //friend static Vex quadrangle::vertex(int, int);
    //20200530 friend Vex vertex(int x1, int y1); 
};
//20200230 Vex vertex(int, int);
class quadrangle
{
private:
    /*class Vex
    { 
    private:
        friend class quadrangle;
        //friend Vex vertex(int x1, int y1);
        int x;
        int y;
    public:
        Vex vertex(int x1, int y1)
        {
            x = x1;
            y = y1;
            return *this;
        };
        Vex(){x = 0; y = 0;};
    };*/
    Vex *vertices;
    //static Vex origin;
    //friend Vex vertex(int x1, int y1);
public:
    /*class Vex
    { 
    private:
        friend class quadrangle;
        //friend Vex vertex(int x1, int y1);
        int x;
        int y;
    public:
        Vex vertex(int x1, int y1)
        {
            x = x1;
            y = y1;
            return *this;
        };
        Vex(){x = 0; y = 0;};
    };*/
    
    /*Vex vertex(int x1, int y1)
    {
        Vex *result;
        result->x = x1;
        result->y = y1;
        return *result;
    }*/
    quadrangle();
    quadrangle(Vex vertex1, Vex vertex2, Vex vertex3, Vex vertex4);
    quadrangle(Vex vertex1, Vex vertex2);
    void draw();
    void move(Vex move1);
    static Vex origin;
    static Vex vertex(int, int);
    //friend Vex vertex(int x1,int y1);
/*private:
    Vex *vertices;
    static Vex origin;*/ //搭配class Vex 宣告在public 
};
//Vex quadrangle::origin;
#endif

