#include <iostream>
using std::cout; using std::endl;
#include "Package.h"// Package class definition
int main()
{
    Package package1("Lou Brown", "Boston","Mary Smith", "New York", 8.5, .5 );
    TwoDayPackage package2("Lisa Klein", "Somerville",
    "Bob George", "Cambridge", 10.5, .65, 2.0 ); 
    OvernightPackage package3("Ed Lewis", "Boston", "Don Kelly", "Denver",
    12.25, .7, .25 );
    /* display the packagg's information */
    package1.display();
    cout << endl;
    package2.display();
    cout << endl;
    package3.display();
    cout << endl;
    return 0;
} 
