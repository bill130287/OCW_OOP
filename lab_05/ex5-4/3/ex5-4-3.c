#include <iostream>
#include "vector.h"
using std::cout;
using std::endl;
using std::cin;

int main()
{
    int *array1,*array2;
    int dim1 = 0, dim2 = 0;
    int x;
    /* read numbers from screen for array1 and array2 */
    /* enter -1 to end input */
    array1 = new int [20];
    array2 = new int [20];
    
    cout << "Enter the elements for array (-1 to end):" << endl;
    while (cin >> x)
    {
        if (x == -1) break;
        array1[dim1] = x;
        dim1++;
    }
    
    cout << "Enter the elements for array (-1 to end):" << endl;
    while (cin >> x)
    {
        if (x == -1) break;
        array2[dim2] = x;
        dim2++; 
    }
    /* return the dimension of each array */
    Vec vec1(array1,dim1);
    Vec vec2;
    vec2.assign(array2,dim2);

    cout << "vec1(sorted): ";
    vec1.sort();
    vec1.printVec();
    cout << "vec2(sorted): ";
    vec2.sort();
    vec2.printVec();
    bool isEqual = vec1.isEqual(vec2);
    /* print out the message if vec1 and vec2 are the same or not*/
    if (isEqual) cout << "vec1 and vec2 are the same" << endl;
    else cout << "vec1 and vec2 are not the same" << endl;

    Vec vec3;
    vec3.unionSet(vec1,vec2); // vec3 is union set of vec1 and vec2

    cout << "vec3: ";
    vec3.printVec();
    vec3.sort();
    cout << "vec3(sorted): ";
    vec3.printVec();

    cout << "Min in vec1 and vec2: " << vec3.min() << endl;
    cout << "Max in vec1 and vec2: " << vec3.max() << endl;
    int target = 19;
    bool findInVec = vec3.find(target);
    /* print out the message if target is found or not. */
    if (findInVec) cout << "The target: " << target << " is found." << endl;
    else cout << "The target: " << target << " is not found." << endl;

    Vec vec4;
    vec4 = vec3.inpendetSet();
    cout << "vec4: ";
    vec4.printVec();
    delete [] array1;
    delete [] array2;
    return 0;
}
