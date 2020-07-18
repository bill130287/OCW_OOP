#ifndef HEADER_H
#define HEADER_H
using namespace std;

class Score
{
private:
   int score[5]; 
public:
    //Score() {;}
    Score(int SC_1=0, int SC_2=0, int SC_3=0, int SC_4=0, int SC_5=0);
    Score(int *SC);
    void SetScore(int *SC);
    int sum5();
    //~Score();
    
};

class Test : public Score
{
public:
    //Test() {Score();}
    Test(int t1=0, int t2=0, int t3=0, int t4=0, int t5=0):Score(t1, t2, t3, t4, t5) { }
    Test(int *t):Score(t) { }
    void SetTest(int *t) {Score::SetScore(t);}
    double sum() {return double(Score::sum5());}
};

class Sport : public Score
{
public:
    //Sport() {Score();}
    Sport(int s1=0, int s2=0, int s3=0, int s4=0, int s5=0):Score(s1, s2, s3, s4, s5) { }
    Sport(int *s):Score(s) { }
    void SetSport(int *s) {Score::SetScore(s);}
    int sum() {return Score::sum5();}

};

class evaluation : public Test, public Sport
{
public:
    evaluation() {Test(); Sport();}
    evaluation(int *t, int *s): Test(t), Sport(s) { }
    void SetTestAndSport(int *t, int *s){Test::SetTest(t); Sport::SetSport(s);}
    double Average() {return Test::sum() / 5;}
    double Extrapoints() {return double(5 * Sport::sum());}
    double FinalScore() {return Average() + Extrapoints();}
};

class student :  public evaluation
{
private:
    string ID;
    string Name;
    double final_score;
public:
    student() {evaluation();}
    student(string id, string name, int *t, int *s): evaluation(t, s) {ID = id; Name = name; final_score = FinalScore();}
    void SetInformation(int *t, int *s, string id, string name);
    void Set_FinalScore() {final_score = evaluation::FinalScore();} 
    string GetID() {return ID;}
    string GetName() {return Name;}
    double GetFinalScore() {return final_score;}

};

class school
{
private:
    student *Student;
    size_t num;
public:
    school(char *argv);
    void report(char *argv); 
};
#endif
