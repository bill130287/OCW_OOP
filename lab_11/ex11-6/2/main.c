#include <iostream>
#include "Mtx.h"

int main()
{ 
    FullMatrix A(2);
    A(0,0) = 5; A(0,1) = 4; A(1,0) = 3; A(1,1) = 6; A(100,100) = 10;
    A.showMatrix();
    cout << endl;
    
    SymmetricMatrix B(2);
    B(0,0) = 5; B(1,0) = 3; B(1,1) = 6; B(100,100) = 10;
    B.showMatrix();
    cout << endl;
    
    UpperTriMatrix C(2);
    C(0,0) = 5; C(0,1) = 3; C(1,1) = 6; C(100,100) = 10;
    C.showMatrix();
    cout << endl;
    
    LowTriMatrix D(2);
    D(0,0) = 5; D(1,0) = 3; D(1,1) = 6; D(100,100) = 10;
    D.showMatrix();
    cout << endl;
    // you should not assign A(100,100), B(100,100), C(100,100) and D(100,100)
    
    UpperTriMatrix E(2);
    E(0,0) = 5; E(1,0) = 3; E(1,1) = 6; // you should not assign E(1,0)
    E.showMatrix();
    cout << endl;
    
    LowTriMatrix F(2);
    F(0,0) = 5; F(0,1) = 3; F(1,1) = 6; // you should not assign F(0,1)
    F.showMatrix();
    cout << "----------------" << endl;
    Mtx *vec[6];
    //Mtx *a = &C;
    vec[0] = &A; vec[1] = &B;
    vec[2] = &C; vec[3] = &D;
    vec[4] = &E; vec[5] = &F;
    for (int i=0;i<6;i++)
    {
        vec[i]->showMatrix(); 
        cout << endl;
    }
    return 0; 
}
