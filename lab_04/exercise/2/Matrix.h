// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H
/* Write class definition for Matrix */
class Matrix
{
private:
    int **mat;
    size_t size;

public:
    void assignDimension(int n);
    void assignElements();
    void printMatrix();
    void assignMatrix(Matrix mat);
    void transposeMatrix();
    Matrix addMatrix(Matrix mat);
    Matrix subtractMatrix(Matrix mat);
    Matrix multiplyMatrix(Matrix mat);
    
};
#endif 
