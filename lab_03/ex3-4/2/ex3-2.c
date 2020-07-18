#include <iostream>
#define row 5
#define column 6

using namespace std;
void PrintCard(const int);

size_t previous, current, iter = 0;
int score = 0;

char star[row*column];
const char Alphabet[row*column] = { 'G','B','C','E','T','Z', 
                                    'R','Q','P','R','D','E', 
                                    'Z','X','A','H','P','V', 
                                    'T','H','S','G','D','S', 
                                    'A','B','Q','V','C','X'};
 
int main()
{
    int index=-1;
    for (int i=0; i<row*column; i++)
    {
        star[i] = '*'; 
    } 
    for (int i=0; i<row*column; i++)
    {
        cout << star[i] << " ";
        if (i%6 == 5) cout << endl; 
    }

    while(1)
    {
        cout << "Please enter card index(0~29). If you want to exit(-1): ";
        cin >> index;
        //iter += 1;
        if (index == -1) exit(1);
        PrintCard(index);
        cout << "score: " << score << endl;  
        if (score == row*column/2)
        { 
            break;
        }

    }
    cout << "Congratulation!"<< endl;
    return 0;
        
}

void PrintCard(const int index)
{ 
    if (index < 0 || index >= row*column)
    {
        cout << "index " << index << " is out of range." << endl; 
        for (int i=0; i<row*column; i++)
        {
            cout << star[i] << " ";
            if (i%6 == 5) cout << endl;
        }
    }

    else
    {
        //if (iter == 1) previous = index;
        //else if (iter == 2) current = index;
        if (star[index] == '*') 
        { 
            //cout << "iter: " << iter << endl;
            iter += 1;
            star[index] = Alphabet[index];
            for (int i=0; i<row*column; i++)
            {
                cout << star[i] << " ";
                if (i%6 == 5) cout << endl; 
            }
            if (iter == 1) previous = index;
            if (iter == 2)
            {
                current = index;
                if (Alphabet[previous] != Alphabet[current])
                {
                    star[previous] = '*';
                    star[current] = '*';
                    cout << "Try Again!" << endl;
                    for (int i=0; i<row*column; i++)
                    {
                        cout << star[i] << " ";
                        if (i%6 == 5) cout << endl; 
                    }
                }
                else
                {
                    cout << "Good Job!" << endl; 
                    score += 1;
                }
                previous = 0;
                current = 0;
                iter = 0;
            }
        }
        else
        {
            cout << "The card index " << index << " is already opened" << endl;
            for (int i=0; i<row*column; i++)
            {
                cout << star[i] << " ";
                if (i%6 == 5) cout << endl; 
            }
        }
    }
}   
