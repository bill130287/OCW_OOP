#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "header.h"
using namespace std;

Score::Score(int SC_1, int SC_2, int SC_3, int SC_4, int SC_5)
{
    score[0] = SC_1;
    score[1] = SC_2;
    score[2] = SC_3;
    score[3] = SC_4;
    score[4] = SC_5;
}

Score::Score(int *SC)
{
    for (int i=0; i<5; i++)
    {
        score[i] = SC[i]; 
    } 
}

void Score::SetScore(int *SC)
{
    for (int i=0; i<5; i++)
    {
        score[i] = SC[i]; 
    } 
}

int Score::sum5()
{
    int sum = 0;

    for (int i=0; i<5; i++)
    {
        sum += score[i];     
    } 

    return sum;
}

/*Score::~Score()
{
    delete [] score; 
}*/

void student::SetInformation(int *t, int *s, string id, string name)
{
    evaluation::SetTestAndSport(t,s);
    ID = id;
    Name = name;
    final_score = evaluation::FinalScore(); 
    /*cout << "ID: " << ID << endl;
    cout << "Name: " << Name << endl;
    cout << "Final_score: " << final_score << endl;*/
}

school::school(char *argv)
{
    ifstream inFile(argv);
    if (inFile.fail())
    {
        cerr << "File open failed." << endl; 
    }
    //cout << "inFile ok!" << endl; 
    int student_i = 0;
    string buffer, id, name;
    int *t, *s;
    t = new int [5];
    s = new int [5];
    istringstream inStr;

    getline(inFile, buffer);
    inStr.str(buffer);
    inStr >> num;
    inStr.clear();

    //cout << "inFile num: " << num << endl;
    Student = new student [num];

    while(getline(inFile, buffer))
    {
        //cout << buffer << endl;
        inStr.str(buffer);
        inStr >> id;
        inStr >> name;
        
        for (int j=0; j<5; j++)
        {
            inStr >> t[j];
            //cout << "t" << j << ": " << t[j] << endl; 
        }

        for (int j=0; j<5; j++)
        {
            inStr >> s[j]; 
            //cout << "s" << j << ": " << s[j] << endl;
        }
        
        Student[student_i].SetInformation(t, s, id, name);
        //student_i += 1;
        //cout << student_i << endl;
        cout << Student[student_i].GetID() << " " << Student[student_i].GetName() << " "
             << fixed << setprecision(1) << Student[student_i].GetFinalScore() << endl; 
        student_i += 1;

        inStr.clear();
    }

    delete [] t;
    delete [] s;
    inFile.close();
}

void school::report(char *argv)
{
    ofstream outFile(argv);
    if (outFile.fail())
    {
        cerr << "output file open fail." << endl; 
    } 

    /*size_t student_num = 0;
    cout << sizeof(Student[0].GetID()) << endl;
    cout << "sizeof(Student): " << sizeof(Student) << endl;
    cout << "sizeof(Student[0]): " << sizeof(Student[0]) << endl;
    student_num = sizeof(Student) / sizeof(Student[0]);*/
    //cout << "student_num: " << student_num << endl;
    double average = 0;
    
    for (int i=0; i<num; i++)
    {
        outFile << Student[i].GetID() << " " << Student[i].GetName() << " "
                << fixed << setprecision(1) << Student[i].GetFinalScore() << endl; 
        
        average += Student[i].GetFinalScore();
    }
    average /= num;

    outFile << "Average: " << fixed << setprecision(1) << average;

    outFile.close();
    
}
