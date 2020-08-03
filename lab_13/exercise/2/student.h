#ifndef STUDENT_H
#define STUDENT_H
class student
{
private:
    std::string Name;
    double final_score;
public:
    student();
    student(std::string name, double FS);
    void SetInfor(std::string name, double FS); 
    std::string GetName() const;
    double Get_FinalScore() const;
    ~student();
    void operator =(const student &st1);
};

#endif
