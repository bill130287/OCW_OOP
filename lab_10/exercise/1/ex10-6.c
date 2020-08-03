#include <iostream>
#include "head.h"
int main()
{
 Point2D p(2,2);
 Point2D *vec = new Point2D [3];
 vec[0].Set(2,1);
 vec[1].Set(8,1);
 vec[2].Set(5,6);

 Circle_in_Triangle ct(p,1,255,vec);
 ct.draw();

 return 0;
}
