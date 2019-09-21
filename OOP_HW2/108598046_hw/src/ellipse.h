#ifndef ELLIPSE_H
#define ELLIPSE_H
#include<math.h>
#include "shape.h"
class Ellipse:public Shape
{
 public:
     Ellipse(double semiMajorAxes,double semiMinorAxes):_semiMajorAxes(semiMajorAxes), _semiMinorAxes(semiMinorAxes)
     {
         //_semiMajorAxes = r_a;
         //_semiMinorAxes = r_b;

         if( _semiMajorAxes < _semiMinorAxes )
         {
             double tmp = _semiMajorAxes;
             _semiMajorAxes = _semiMinorAxes;
             _semiMinorAxes = tmp;
         }
     }
     double area() const
     {
         return M_PI * _semiMajorAxes * _semiMinorAxes ;
     }

     double perimeter() const // perimeter formula: 2π * semiMinorAxes + 4(semiMajorAxes-semiMinorAxes)
     {
         return 2 * M_PI * _semiMinorAxes + 4 * ( _semiMajorAxes - _semiMinorAxes );
     }

     double sumOfSquares() const
     {
         double area_Ans = area();
         double peri_Ans = perimeter();
         return area_Ans * area_Ans + peri_Ans * peri_Ans ;
     }

private:
    double _semiMajorAxes , _semiMinorAxes;
};
#endif
