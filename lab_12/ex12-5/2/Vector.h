#ifndef vECTOR_H
#define vECTOR_H
template <class T>
class Vector
{
private:
    int len;
    T* vec;
public:
 // add any member if necessary
    Vector(int n, int data);
    Vector(int n, T *A_data);
    T Getvec_index(int i) const;
    int Getlen() const;
    void display() const; 
    void operator +=(Vector &v1);
    //void operator +=(Vector<Point2D> &v1);
    template<class S>
    friend S dot(const Vector<S> &, const Vector<S> &);
};
#endif
