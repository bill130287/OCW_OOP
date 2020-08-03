#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <typeinfo>
#include <iomanip>
using namespace std;

typedef struct
{
    int *data;
    int length;
    bool sign;
}BIGNUMBER;


void ReadTextFile(char *, BIGNUMBER &, BIGNUMBER &);
BIGNUMBER BigNumberOperation(BIGNUMBER , BIGNUMBER , const char );
void WriteResults(const char *, const BIGNUMBER *);

int main(int argc, char *argv[])
{
    BIGNUMBER a, b;
    ReadTextFile(argv[1], a, b);
    
    BIGNUMBER results[2];
    //cout << results[1].data[results[1]].length-1] << endl;
    //cout << "main sizeof(results)" << sizeof(results) << endl;
    /*cout << "a.length" << a.length << endl;
    cout << "b.length" << b.length << endl;
    for (int i = 0; i<7; i++)
    {
       cout << a.data[i] ; 
    }
    cout << endl;
    for (int i = 0 ; i<7; i++)
    {
       cout << b.data[i]; 
    }*/

    results[0] = BigNumberOperation(a,b,'+');
    results[1] = BigNumberOperation(a,b,'-');

    WriteResults(argv[2], results);
    cout << results[1].data[results[1].length-1] << endl;

    return 0;
}

void ReadTextFile(char *argv, BIGNUMBER &a, BIGNUMBER &b)
{
    ifstream inFile(argv);
    string line_a, line_b;
    int i = 0;
    int max_size;
    if(inFile.fail())
    {
        cout << "The file open is error" << endl;
        exit(1); 
    } 

    while(i < 2)
    {   
        if (i == 0)
        {
            getline(inFile, line_a);
            i++;
        }

        else if (i == 1)
        {
            getline(inFile, line_b);
            i++; 
        }

        //cout << "i is" << i << endl;
        else
        {
            cout << "ReadTextFile line is not enough"  << endl;
            exit(1); 
        } 
    }
    /*max_size = line_a.length() > line_b.length() ? line_a.length() : line_b.length();
    cout << "max_size= " << max_size << endl;
    cout << "line[0]: " << line_a << endl;
    cout << "line[1]: " << line_b << endl;*/
    //cout << "line_a[0]: " << line_a[0] << endl;
    //a.data = new int[max_size];
    //b.data = new int[max_size];
    a.length = line_a.size();
    b.length = line_b.size();
    a.sign = atoi(line_a.c_str()) >= 0 ? 0 : 1;
    b.sign = atoi(line_b.c_str()) >= 0 ? 0 : 1;

    if (a.sign) a.length--;
    if (b.sign) b.length--;
    max_size = line_a.length() > line_b.length() ? line_a.length() : line_b.length();
    a.data = new int[max_size];
    b.data = new int[max_size];

    //cout << "a.length" << a.length << endl;
    for (int j=0; j<max_size; j++)
    {
        if (j >= a.length) //(j < max_size - a.length)
        {
            a.data[j] = 0; 
            //cout << "Hi" << endl;
        } 

        else
        {
            if (a.sign)
                a.data[j] = int(line_a[a.length -j] - 48);
            else
                a.data[j] = int(line_a[a.length - j - 1] -48);
            //a.data[j] = int(line_a[j - (max_size-a.length)] - 48);
            //cout << a.data[j] << endl;
        }
    }

    for (int j=0; j<max_size; j++)
    {
        if (j >= b.length)//(j < max_size -b.length)
        {
            b.data[j] = 0; 
        } 
        else
        {
            if (b.sign)
                b.data[j] = int(line_b[b.length - j ] - 48);
            else
                b.data[j] = int(line_b[b.length -j -1] -48);
            //b.data[j] = int(line_b[j - (max_size-b.length)] - 48);
            //b.data[j] = atoi(line_b[j - (max_size-b.length)]); 
        }
    }
    //cout << "Exit" << endl;

}

BIGNUMBER BigNumberOperation(BIGNUMBER a, BIGNUMBER b, const char op)
{
    int max_length = 0;//, Remax_length = 0; //Remax_length 要算進位時的數字
    bool change_flag = 0;
    BIGNUMBER result, tmp;
    int *TmpData;
    max_length = a.length > b.length ? a.length : b.length;
    
    if (op == '+')
    {
        if (a.sign == b.sign)
        {
            result.sign = a.sign;
            result.length = max_length+1;
            result.data = new int [max_length+1]; 
            result.data[max_length] = 0;
            for (int i=0; i<max_length; i++)
            {   
                result.data[i] = a.data[i] + b.data[i];    
            }
            /*上面為每個位數相加 接下來要檢查有沒有進位*/
            for (int i=0; i<max_length; i++)
            {
                if (result.data[i] >= 10)
                {
                    result.data[i] -= 10;
                    result.data[i+1] ++; 
                }
            }

            if (result.data[max_length] <= 0)
            {
                result.length -= 1; 
            }
            return result;
        } 

        else 
        {
            for (int i=max_length-1; i>=0; i--)
            {
               if (b.data[i] > a.data[i])
               {
                    return BigNumberOperation(b, a, op);
               } 
            }
            result.sign = a.sign;
            result.length = max_length;
            result.data = new int [max_length];

            for (int i=0; i<max_length; i++)
            {
                if (a.data[i] - b.data[i] < 0)
                { 
                    a.data[i+1] -= 1;
                    a.data[i] += 10;
                    result.data[i] = a.data[i] - b.data[i];
                } 
                else
                { 
                    result.data[i] = a.data[i] - b.data[i];
                }
            }

            for (int i=max_length-1; i<=0; i--)
            {
                if (result.data[i] == 0)
                {
                    result.length--; 
                } 
                else
                {
                    break; 
                }
            }
        }
        return result;
    }

    else if (op == '-')
    {
        result.data = new int [max_length];
        result.length = max_length;
        int flag = 0;
        if (a.sign == b.sign)
        {
            if (a.length == b.length)
            {
               for (int i=max_length-1; i<=0; i--)
               {
                    if (a.data[i] > b.data[i])
                    {
                        result.sign = a.sign;
                        flag = 1;
                        break; 
                    } 
                    else if (a.data[i] < b.data[i]) 
                    {
                        result.sign = !a.sign;
                        tmp = b;
                        b = a;
                        a = tmp;
                        flag = 1; 
                        break;
                    }
               }
               if (flag == 0)
               {
                    result.sign = 0; 
               } 
            } 
            else if (a.length < b.length)
            {
                result.sign = !a.sign;
                tmp = b;
                b = a;
                a =tmp; 
            }
            else
            {
                result.sign = a.sign; 
            }
            for (int i=0; i<max_length; i++)
            {
                if (a.data[i] < b.data[i])
                {
                    a.data[i+1] -= 1;
                    a.data[i] +=10;
                    result.data[i] = a.data[i] - b.data[i]; 
                }
                else
                {
                    result.data[i] = a.data[i] - b.data[i]; 
                }
            }
            for (int i=max_length-1; i>=0; i--)
            {
               if (result.data[i] == 0)
               {
                    result.length--; 
               } 
               else 
               {
                    break; 
               }
            }
            return result;
        }

        else
        {
            result.data = new int [max_length+1];
            result.length = max_length+1;
            result.sign = a.sign;
            result.data[max_length] = 0;
            for (int i=0; i<max_length; i++)
            {
                result.data[i] = a.data[i] + b.data[i]; 
            } 
            for (int i=0; i<max_length; i++)
            {
                if (result.data[i] >= 10)
                {
                    result.data[i] -= 10;
                    result.data[i+1] += 1; 
                } 
            }
            for (int i=max_length; i>=0; i--)
            {
                if (result.data[i] == 0)
                {
                    result.length --; 
                } 
                else
                {
                    break; 
                }
            } 
            return result;
        }
    }
    else
    {
        cout << "In BIGNUMBER Operation: NO this operation- ";
        cout << op << endl;
        exit(1);
    }

}

void WriteResults(const char *argv, const BIGNUMBER *results)
{
    int re_length = 2; //sizeof(results[0]);
    //cout << "re_length0: " << re_length << endl;
    //cout << "re_length1: " << sizeof(results[1]) <<endl;
    //cout << "re_length: " << results[1] << endl;
    bool flag;
    ofstream outFile(argv);
    if (outFile.fail())
    {
        cout << "WriteResult Openfile is fail" << endl;
        exit(1); 
    }
    for (int i=0; i<re_length; i++)
    {
        for (int j=results[i].length-1; j>=0; j--)
        {   
            if ( j == results[i].length-1 && results[i].sign == 1)
            {
                outFile << "-"; 
            }
            outFile << results[i].data[j]; 
        }
        if (i == 0)
        {
            if (results[i].sign == 0)
                outFile << setw(20-results[i].length) << "// A + B" << endl; 
            else
                outFile << setw(20-results[i].length-1) << "// A + B" << endl;
        }
        else
        {   
            if (results[i].sign == 0)
                outFile << setw(20-results[i].length) << "// A - B" << endl; 
            else
                outFile << setw(20-results[i].length-1) << "// A - B" << endl;
        }
    } 
    outFile.close();
}

