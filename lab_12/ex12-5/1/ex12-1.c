#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Point2D
{
private:
    int x;
    int y;
public:
 // add any member if necessary
    void SetPoint2D(int x1, int y1){x = x1; y = y1;}
    void displayPoint2D(){cout << '(' << x << ',' << y << ')';}
    int GetX(){return x;}
    int GetY(){return y;}
};

template <class T>
T* new1D(int &n, int k = 0)
{
     T *vec;
     vec = new T [n];
     return vec;
}

template <class T = int>
void rand1D (T *vec, int n)
{
    const int bucket = RAND_MAX / n;
    int r;

    for (int i=0; i<n; i++)
    {
        do
        {
            r = rand() / bucket; 
        }while (r >= n);

        vec[i] = r;
    }
}

template <>
void rand1D<double> (double *vec, int n)
{
    double r; //= ((RAND_MAX - rand()) / static_cast<double>(RAND_MAX)) * 10.0;
    for (int i=0; i<n; i++)
    {
        r = (double(RAND_MAX - rand()) / static_cast<double>(RAND_MAX)) * 10.0;
        vec[i] = r;
    }

}

template <>
void rand1D<char> (char *vec, int n)
{
    const int bucket = RAND_MAX / 26; //26 means a~z
    int r;
    for (int i=0; i<n; i++)
    { 
        do
        {
            r = rand() / bucket; 
        }while (r >= 26);
        r += 97;
        vec[i] = char(r);
    }

}

template <>
void rand1D<Point2D> (Point2D *vec, int n)
{
    const int bucket = RAND_MAX / n;
    int x1, y1;

    for (int i=0; i<n; i++)
    {
        do
        {
            x1 = rand() / bucket; 
        }while (x1 >= n);

        do
        {
            y1 = rand() / bucket; 
        }while (y1 >= n);

        vec[i].SetPoint2D(x1, y1); 
    }
     
}

template <class T>
void display1D (T *vec, int n)
{
    for (int i=0; i<n; i++)
    {
        cout << fixed << setprecision(2) << vec[i] << ' '; 
    } 

    cout << endl;
}

template <>
void display1D<Point2D> (Point2D *vec, int n)
{
    for (int i=0; i<n; i++)
    {
         vec[i].displayPoint2D();
         cout << ' ';
    }     

    cout << endl;
}

template <class T>
void sort1D (T *vec, int n)
{
    T key;
    int j;
    for (int i=1; i<n; i++)
    {
        key = vec[i];
        j = i-1;

        while (j >= 0 && vec[j] > key)
        {
            vec[j+1] = vec[j];
            j -= 1; 
        }
        vec[j+1] = key;
    }   
}

template <>
void sort1D<Point2D> (Point2D *vec, int n)
{
    int x_key, y_key, j;

    for (int i=1; i<n; i++)
    {
        x_key = vec[i].GetX();
        y_key = vec[i].GetY();
        j = i-1;

        while (j >= 0 && vec[j].GetX() >= x_key)
        {
            if (vec[j].GetX() == x_key)
            {
                if (vec[j].GetY() > y_key)
                {
                    vec[j+1] = vec[j];
                    j -= 1; 
                } 
                else 
                    break;
            }
            else
            {
                vec[j+1] = vec[j]; 
                j -= 1;
            }
        }

        vec[j+1].SetPoint2D(x_key, y_key);
    } 
}

template <class T>
void analysis(int n, int k = 0)
{
    T *vec = new1D<T> (n, k);
    rand1D<T>(vec,n);
    // for int 1~10, for double 0.00~10.00, for char a~z,
    // for Point2D x: 0~9 y:0~9
    display1D<T>(vec,n);
    sort1D<T>(vec,n);
    display1D<T>(vec,n);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    srand(25);

    analysis<int>(n); 
    analysis<double>(n);
    analysis<char>(n);
    analysis<Point2D>(n); 

    return 0;
}
