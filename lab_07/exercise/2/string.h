// my_string.h
#include <iostream>
#ifndef STRING_H
#define STRING_H
class string
{
private:
    char *p;
public:
    string();
    string (const char *s);
    //string (const string &s);
    ~string() {if(p) { delete [] p; p = NULL; } }
    friend std::ostream& operator << (std::ostream&, const string &s);
    friend string operator + (const string &s, const string &t);
    bool operator <= (const string &s);
};
#endif
