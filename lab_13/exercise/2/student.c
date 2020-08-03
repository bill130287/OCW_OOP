#include <iostream>
#include <string>
#include "student.h"
using namespace std;

student::student()
{
   ; 
}

student::student(string name, double FS)
{
    Name = name;
    final_score = FS; 
}

void student::SetInfor(string name, double FS)
{
    Name = name;
    final_score = FS; 
}

string student::GetName() const
{
    return Name;
}

double student::Get_FinalScore() const
{
    return final_score;
}

student::~student()
{
    ; 
}

void student::operator =(const student &st1)
{
    Name = st1.Name; 
    final_score = st1.final_score;
    //return *this;
}
