#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
string longest_W;
size_t num_w = 0;

int Read_File(string &in_F)
{
    ifstream in_File(in_F.c_str());
    if (!in_File) cerr << "File " << in_F << " can not open.";
    //cout << "Read_File open" << endl;
    string line, word;
    istringstream line_stream;
    size_t Length_W = 0, MaxL_W = 0;

    while (getline(in_File, line))
    {
        line_stream.str(line);
        while (line_stream >> word)
        { 
            Length_W = word.length();
            
            if (!isalpha(word[word.length()-1])) Length_W -= 1;
            
            if (Length_W >= MaxL_W)
            {
                MaxL_W = Length_W;
                longest_W = word;
            }

            num_w += 1;
        }

        line_stream.clear();

    }

    in_File.close();
    return MaxL_W;
}

void Display_outF(const size_t &MaxL_W, string &out_F)
{
    ofstream out_File(out_F.c_str());
    if (!out_File) cerr << "File " << out_F << " can not open";
    
    if (MaxL_W < longest_W.length()) longest_W[longest_W.length()-1] = '\0';

    out_File << "The number of words read is " << num_w << endl;
    out_File << "The longest word has a length of " << MaxL_W << endl;
    out_File << "The longest word is " << longest_W << endl;

    out_File.close();
}
int main()
{
    string in_F;
    string out_F;
    size_t MaxL_W;
    cout << "Please enter input file name:";
    cin >> in_F;
    cout << "Please enter output file name:";
    cin >> out_F;

    MaxL_W = Read_File(in_F);
    Display_outF(MaxL_W, out_F);
    
}
