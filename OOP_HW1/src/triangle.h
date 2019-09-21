#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<math.h>
#include <string>
#include "shape.h"
using namespace std;

class Triangle:public Shape
 {
 public:


     Triangle(double x1, double y1, double x2, double y2, double x3, double y3):_x1(x1), _x2(x2), _x3(x3), _y1(y1), _y2(y2), _y3(y3)
     {
         a = sqrt( ( _x1 - _x2 ) * ( _x1 - _x2 ) + ( _y1 - _y2 ) * ( _y1 - _y2 ) );
         b = sqrt( ( _x2 - _x3 ) * ( _x2 - _x3 ) + ( _y2 - _y3 ) * ( _y2 - _y3 ) );
         c = sqrt( ( _x1 - _x3 ) * ( _x1 - _x3 ) + ( _y1 - _y3 ) * ( _y1 - _y3 ) );
         /*
         cout << "_x1 = " << _x1 << ", _y1 = " << _y1 << endl;
         cout << "_x2 = " << _x2 << ", _y2 = " << _y2 << endl;
         cout << "a = " << a << endl;
         cout << "b = " << b << endl;
         cout << "c = " << c << endl;
         */
         isTriangle = true;
         try {

             if ( ( a + b <= c) || ( b + c <= a) || ( a + c <= b) )
             {
                 isTriangle = false;
                 throw string("No a a IsoscelesTriangle.");
             }
         }
         catch(string e)
         {
             std::cout << "No a a IsoscelesTriangle." << std::endl;
         }
     }
     // give you three points (x1,y1), (x2,y2), (x3,y3) to calculate area and perimeter
     double area() const
     {
         double s = ( a + b + c) / 2.0 ;

         return sqrt( s * ( s - a ) * (s - b ) * ( s - c ) );
     }

     double perimeter() const
     {
         return a + b + c ;
     }

     bool isIsoscelesTriangle()
     {
         if (isTriangle == true)
         {
             if( ( a == b ) && ( a != c ) )// a b , c
             {
                 isTriFlag = true;
                 //return true;
             }
             else if ( ( a == c ) && ( a != b ) )// a c , b
             {
                 isTriFlag = true;
                 //return true;
             }
             else if ( ( b == c ) && ( a != b ) )// b c , a
             {
                 isTriFlag = true;
                 //return true;
             }
             else
             {
                 isTriFlag = false;
             }
        }
        else
        {
            isTriFlag = false;
        }

        try{
            if(isTriFlag == false)
            {
                throw string("No a a IsoscelesTriangle.");
            }
        }
        catch(string e)
        {
            std::cout << e << std::endl;
        }

        return isTriFlag;

        //return false;
     }

private:
    double _x1 , _x2, _x3;
    double _y1 , _y2, _y3;
    bool isTriangle = true;
    bool isTriFlag = true;
    double a = 0 , b = 0 , c = 0 ;
 };
 #endif
