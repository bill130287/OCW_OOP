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
    Matrix();
    Matrix(int n);
    Matrix(const Matrix &matrix);
    ~Matrix();
    void assignDimension(int n);
    void assignElements();
    void printMatrix();
    void assignMatrix(Matrix mat);
    void transposeMatrix();
    Matrix addMatrix(const Matrix mat);
    Matrix subtractMatrix(Matrix mat);
    Matrix multiplyMatrix(Matrix mat);
    void multiplyMatrix(const Matrix mat1, const Matrix mat2);
    
};
#endif 
