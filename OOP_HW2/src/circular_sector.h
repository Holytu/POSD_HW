#ifndef CIRCULARSECTOR_H
#define CIRCULARSECTOR_H
#include<math.h>
#include "shape.h"
class CircularSector:public Shape
 {
 public:
     CircularSector(double radius, double degree): _radius(radius), _degree(degree)
     {

     }

     double area() const
     {
         return M_PI * _radius * _radius * ( _degree / 360.0 );
     }

     double perimeter() const
     {
         return 2 * M_PI * _radius * ( _degree / 360.0 ) + 2 * _radius ;
     }

     double sumOfSquares() const
     {
         return area() * area() + perimeter() * perimeter() ;
    }

private:
    double _radius , _degree;
 };

#endif
