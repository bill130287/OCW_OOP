// ex1-2.cpp
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cstring>

const int MAX = 1000;
typedef struct 
{

    char coeff[10];
    int power;
}Items;

typedef struct
{
 Items items[MAX];
 int num_items;
}Poly;

void ReadTextFile(char *, Poly &);
void DifferentationPoly(Poly &);
void PrintComplex(char *, const Poly &);
using namespace std;

int main(int argc, char *argv[])
{
    Poly eq;
    ReadTextFile(argv[1], eq); // process text file
    cout << "num_items = " << eq.num_items << endl;
    cout << "coeff = " << eq.items[2].coeff << endl;
    cout << "power = " << eq.items[2].power << endl;
    DifferentationPoly(eq); // differentiation of polynomials
    cout << "num_items = " << eq.num_items << endl;
    cout << "coeff = " << eq.items[1].coeff << endl;
    cout << "power = " << eq.items[1].power << endl;

    PrintComplex(argv[2], eq); // print the results on file.

    return 0;
} 

void ReadTextFile(char *argv, Poly &eq)
{
    ifstream inFile(argv);
    double coef, pow;
    int str_size = 0, items = 0;
    int pow_flag = 0, final_flag = 0;
    string line;
    string x_F = "", x_B = "";
    while (getline(inFile, line))
    {
        str_size = line.size();
        for (int i=0; i<str_size; i++)
        {
            if (pow_flag && (line[i] == '+' || line[i] == '-')) 
            { 
                pow_flag = 0;
                if (x_B == "") 
                { 
                    eq.items[items].power = 1;
                }
                else eq.items[items].power = atoi(x_B.c_str());
                x_B = "";
                items += 1;
            }
           /* if ((line[i] != 'X' || line[i] != '^') && pow_flag == 0)
            {
                x_F += line[i];
                if (i == str_size-1) strcpy(eq.items[items].coeff, x_F.c_str());
            }*/

            if (line[i] == 'X')
            {   
                if (x_F == "+" || x_F == "-" || x_F == "")
                {
                    strcpy(eq.items[items].coeff, "1");
                    x_F = ""; 
                }
                else
                { 
                    strcpy(eq.items[items].coeff, x_F.c_str());
                    //eq.items[items].coeff = x_F;
                    x_F = "";
                }
                pow_flag = 1;
            }

            if ((line[i] != 'X' || line[i] != '^') && pow_flag == 0)
            {
                x_F += line[i];
                if (i == str_size-1) strcpy(eq.items[items].coeff, x_F.c_str());
            }

            if (pow_flag && (isdigit(line[i]) || line[i] == '-'))
            {
                //if (line[i+1] != '^') x_B = "1";
                x_B += line[i];
            }

        }
        eq.num_items = items + 1;
    }
}

void DifferentationPoly(Poly &eq)
{
    int num_items = eq.num_items;
    char D_coeff[10] ;
    int D_power;
    for (int i=0; i<num_items; i++)
    {   
        if (eq.items[i].power == 0)
        {
            strcpy(eq.items[i].coeff, "0");
            //eq.items[i].power -= 1; 
        }
        
        else
        { 
            //D_coeff = _itoa(atoi(eq.items[i].coeff)*eq.items[i].power);
            sprintf(D_coeff, "%d", atoi(eq.items[i].coeff)*eq.items[i].power);
            strcpy(eq.items[i].coeff, D_coeff);
            eq.items[i].power -= 1;
        }
    }

}

void PrintComplex(char *argv, const Poly &eq)
{
    ofstream outFile(argv);
    int num_items = eq.num_items;

    for (int i=0; i<num_items; i++)
    {   
        if (eq.items[i].power == 0 && eq.items[i].coeff[0] == '0')
            continue;
        else if (eq.items[i].power == 0 && eq.items[i].coeff != "0")
        {     
            if (eq.items[i].coeff[0] == '-')   
                outFile << eq.items[i].coeff;
            else
                outFile << "+" << eq.items[i].coeff;
        }
        else 
        { 
            if (eq.items[i].coeff[0] == '-')
            {   
                if (eq.items[i].power == 1)
                    outFile << eq.items[i].coeff << "X";
                else
                    outFile << eq.items[i].coeff << "X^" << eq.items[i].power;
            }

            else 
            {   
                if (i == 0)
                {   if (eq.items[i].power == 1)
                        outFile << eq.items[i].coeff << "X";
                    else
                        outFile << eq.items[i].coeff << "X^" << eq.items[i].power;
                }
                
                else if (eq.items[i].power == 1)
                    outFile << "+" << eq.items[i].coeff <<  "X";
                else
                    outFile << "+" << eq.items[i].coeff << "X^" << eq.items[i].power;
            }
        } 
    }
    outFile.close();
}
