#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "student.h"
using namespace std;

void ReadFile(ifstream &infile, map<int, student> &classroom)
{
    string buffer, name;
    int id, t, s, sum = 0, bonus = 0;
    double average = 0;
    istringstream inStr;
    size_t n;

    getline(infile, buffer);
    inStr.str(buffer);

    inStr >> n;
    inStr.clear();

    student Student;

    while (getline(infile, buffer))
    {
        inStr.str(buffer);
        inStr >> id;
        inStr >> name;

        for (int i=0; i<5; i++)
        {
            inStr >> t; 
            sum += t;
        }

        for (int i=0; i<5; i++)
        {
            inStr >> s;
            bonus += s;
        }
        
        average = double(sum) / 5;
        bonus *= 5;
        average += double(bonus);

        Student.SetInfor(name, average);
        classroom[id] = Student;
        
        inStr.clear();
        sum = 0;
        bonus = 0;
    }

     
}

int main(int argc, char *argv[])
{
    ifstream infile(argv[1],ios::in);
    if (infile.fail())
    {
        cerr << "File open failed." << endl; 
    }

    map<int, student> classroom;

    // read file and store student’s information
    ReadFile(infile, classroom);

    for (map<int,student>::const_iterator iter = classroom.begin(); iter != classroom.end(); iter++)
    {
        cout << "ID: " << iter->first << ' ';
        cout << "name: " << iter->second.GetName() << ' ';
        cout << "score: " << iter->second.Get_FinalScore();
        cout << endl;
    }

    return 0;
} 
