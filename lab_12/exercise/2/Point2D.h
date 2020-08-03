#ifndef POINT2D_H
#define POINT2D_H
class Point2D
{
private:
    int x;
    int y;
public:
    // add any member if necessary
    Point2D(int x1 = 0, int y1 = 0);
    void SetPoint2D(int x1, int y1);
    void displayPoint2D() const;
    int GetX();
    int GetY();
    friend std::ostream& operator <<(std::ostream &out, Point2D &vertex);
};
#endif
