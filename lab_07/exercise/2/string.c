#include <iostream>
#include <cstring>
#include "string.h"

string::string()
{   
    ; 
}

string::string(const char *s)
{
    int s_len = 0 ;
    s_len = strlen(s);
    p = new char [s_len];
    for (int i=0; i<s_len; i++)
    {
        p[i] = s[i]; 
    }
}

/*string::string(const string &s)
{
    int s_len = 0;
    s_len = strlen(s.p); //const 不能用s->p
    p = new char [s_len];
    for (int i=0; i<s_len; i++)
    {
        p[i] = s.p[i];  //const 不能用s->p 
    } 
}*/

std::ostream& operator << (std::ostream &out, const string &s)
{
    int s_len = strlen(s.p);
    for (int i=0; i<s_len; i++)
    {
        out << s.p[i];       
    } 
    return out;
}

string operator + (const string &s, const string &t)
{
    int s_len = 0, t_len = 0, len = 0;
    s_len = strlen(s.p);
    t_len = strlen(t.p);
    len = s_len + t_len;
    
    string result;
    result.p = new char [len]; //non-memeber function不能用this->p
 
    for (int i=0; i<len; i++)
    {
        if (i < s_len)
        {
            result.p[i] = s.p[i]; 
        } 
        
        else
        {
            result.p[i] = t.p[i - s_len]; 
        }
    } 

    return result;
}

bool string::operator <= (const string &s)
{
     int this_len = 0, s_len = 0;
     this_len = strlen(this->p);
     s_len = strlen(s.p);

     if (this_len <= s_len)
         return true;
     else 
         return false;
}
