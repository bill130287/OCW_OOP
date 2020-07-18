//ex2-1.cpp
//include　File
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

struct Student
{
    string ID;
    string name;
    int score;
    int time; 
};

void ReadTextFile(char *, Student *);
void StudentDataAssign(const string *, Student &);
void PrintStudent(char *, Student *);
void StudentMerge(Student *student , const int p , const int q, const int r);
void StudentMerge_sort(Student *student, const int p, const int r);


int num_student = 0;

int main(int argc, char *argv[])
{
    Student student[5];
    ReadTextFile(argv[1], student);
    StudentMerge_sort(student, 0, num_student-1);
    PrintStudent(argv[2], student);
    return 0;
}

void ReadTextFile(char *argv, Student *student)
{
    ifstream inFile(argv);
    string line[12];
    int i = 0;
    while (getline(inFile, line[i], ' '))
    {
        //cout << line[i] << endl; 
        //cout << line.size() << endl;
        
        //cout << "line[" << i << "]= " << line[i] << endl; 
        i++;
        if (i == 11)
        {
            getline(inFile, line[i], '\n');
            //inFile >> line[i];
            i++; 
        }
        if(i >= 12) 
        { 
            i=0;
            StudentDataAssign(line, student[num_student]);
            //line.clear();
        }
    }
     
    inFile.close();
}

void StudentDataAssign(const string *line, Student &student)
{
    student.ID = line[0];
    student.name = line[1];
    int score = 0;
    for (int i=2; i<11; i++)
    {
        if ( i >= 2 && i <= 4)
        {
            score += 10*atoi(line[i].c_str());
        }
        else if ( i >= 5 && i <= 7)
        {
            score += 20*atoi(line[i].c_str());
        }
        else
        {
            score += 30*atoi(line[i].c_str()); 
        }
    }

    if (score > 100) score = 100;
    
    student.score = score;
    student.time = atoi(line[11].c_str());
    num_student +=1;
}

void PrintStudent(char *argv, Student *student)
{
    ofstream outFile(argv);
    
    for (int i=0; i<num_student; i++)
    {
        outFile << student[i].ID << " " << student[i].name << " "
                << student[i].score << " " << student[i].time << endl; 
    }  

    outFile.close();
}
void StudentMerge(Student *student , const int p , const int q, const int r)
{ 
    int n1,n2,k,i,j;
    n1 = q-p+1;
    n2 = r-q;
    Student L[n1+1], R[n2+1];
    for(i = 0; i < n1; i++)
    {
       L[i] = student[p+i]; //*(a+(p+i));
      //printf("L[%d] = %d \n:",i,L[i]);//Error dection 
    }
    for(j = 0; j < n2 ; j++)
    {
       R[j] = student[q+1+j]; //*(a+((q+1)+j));
      //printf("R[%d] = %d \n:",j,R[j]);//Error dection
    }
    L[n1].score = -99999; //score 由大排到小
    R[n2].score = -99999; 
    L[n1].time = 99999; //time 由小排到大
    R[n2].time = 99999;

    i = 0;
    j = 0;
    for(k = p; k <= r; k++)
    {
       if(L[i].score >= R[j].score)
       {    
            if (L[i].score == R[j].score)
            {
                if (L[i].time <= R[j].time)
                {
                    student[k] = L[i];
                    i++; 
                    //cout << "student" << k << "is " << student[k].ID << endl;
                }

                else
                {
                    student[k] = R[j];
                    j++; 
                    //cout << "student" << k << "is " << student[k].ID << endl;
                }     
            }

            else
            {     
                student[k] = L[i];//*(a+k) = L[i];
                i = i+1;
                //cout << "student" << k << "is " << student[k].ID << endl;
            } 
       }
       else
       {
            student[k] = R[j];//*(a+k) = R[j];
            j = j+1;
            //cout << "student" << k << "is " << student[k].ID << endl;
       } 
    }
}

void StudentMerge_sort(Student *student, const int p, const int r)
{ 
     int q;
     if(p<r)
     {
        q = floor((p+r)/2);
        StudentMerge_sort(student, p, q);
        StudentMerge_sort(student, q+1, r);
        StudentMerge(student, p, q, r);  
     }
}
