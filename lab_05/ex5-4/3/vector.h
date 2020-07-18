#include <iostream>
#ifndef VECTOR_H
#define VECTOR_H
class Vec
{   
private:
    int *Arr;
    size_t dim;
public:
    Vec();
    Vec(int *array1, int dim1);
    void assign(int *array1, int dim1);
    void sort();
    void printVec();
    bool isEqual(Vec vec1);
    void unionSet(Vec vec1, Vec vec2);
    int min();
    int max();
    bool find(int target);
    Vec inpendetSet();
     
};

#endif
