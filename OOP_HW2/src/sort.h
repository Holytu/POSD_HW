#ifndef SORT_H
#define SORT_H
#include "../src/shape.h"
#include "../src/circular_sector.h"
#include "../src/triangle.h"
#include "../src/ellipse.h"
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

bool areaAscendingComparison(Shape *a, Shape *b); // AscendingComparison
bool areaDescendingComparison(Shape *a, Shape *b); // DescendingComparison

bool perimeterAscendingComparison(Shape *a, Shape *b);
bool perimeterDescendingComparison(Shape *a, Shape *b);

bool sumOfSquaresAscendingComparison(Shape *a, Shape *b);
bool sumOfSquaresDescendingComparison(Shape *a, Shape *b);

class AscendingComparison{
public:
    AscendingComparison(string str)
    {
        _str = str;
    }
    bool operator()(Shape *a, Shape *b)
    {
        if(_str == "area")
        {
            return a->area() < b->area();
        }
        else if(_str == "perimeter")
        {
            return a->perimeter() < b->perimeter();
        }
        else
        {
            return a->sumOfSquares() < b->sumOfSquares();
        }
    }

    string getStr()
    {
        return _str;
    }
    void resetStr()
    {
        _str = "";
    }
private:
    string _str = "";
};
class DescendingComparison{
public:
    DescendingComparison(string str):_str(str){}

    bool operator()(Shape *a, Shape *b)
    {
        if(_str.compare("area") == 0)
        {
            return a->area() > b->area();
        }
        else if(_str.compare("perimeter") == 0)
        {
            return a->perimeter() > b->perimeter();
        }
        else if(_str.compare("sumOfSquares") == 0 )
        {
            return a->sumOfSquares() > b->sumOfSquares();
        }

    }
    string getStr()
    {
        return _str;
    }
    void resetStr()
    {
        _str = "";
    }
private:
    string _str = "";
};



class Sort {
    public:
      Sort(std::vector<Shape*>* v): _v(v){}
      ///Area
      template<class T>
      void sortArea(T sol)
      {
          std::sort( (*_v).begin(), (*_v).end() , sol);
      }
      ///Perimeter
      template<class T>
      void sortPerimeter(T sol)
      {
          std::sort( (*_v).begin() , (*_v).end() , sol);
      }

      ///SumOfSquares
      template<class T>
      void sortSumOfSquares(T sol)
      {
          std::sort( (*_v).begin() , (*_v).end() , sol);
      }

      template<class T>
      void quickSort(T sortWay)
      {
          qSort( (*_v).begin() , (*_v).end() - 1 , sortWay);
      }

      template < typename I , typename C>
      void qSort( I start , I tail , C asc)
      {
          if(distance(start , tail) >= 2)
          {
               I p = partition( start, tail, asc);

               qSort( start , p - 1 , asc );
               qSort( p + 1 , tail  , asc );
          }
      }

      template < typename I , typename C>
      I partition( I start , I tail , C asc)
      {
          I i = start - 1;
          I it = start;
          for ( ; it < tail ; it++ )
          {
              if( asc(*it, *tail) )
              {
                  i++;
                  std::swap( *i, *it);
              }
          }
          std::swap(*(i+1),*tail);
          return ++i;
      }
    private:
      std::vector<Shape*>* _v;
};
bool areaAscendingComparison(Shape *a, Shape *b)
{
    return a->area() < b->area() ;
}
bool areaDescendingComparison(Shape *a, Shape *b)
{
    return a->area() > b->area() ;
}

bool perimeterAscendingComparison(Shape *a, Shape *b)
{
    return a->perimeter() < b->perimeter() ;
}
bool perimeterDescendingComparison(Shape *a, Shape *b)
{
    return b->perimeter() < a->perimeter();//
}

bool sumOfSquaresAscendingComparison(Shape *a, Shape *b)
{
    return a->sumOfSquares() < b->sumOfSquares() ;
}
bool sumOfSquaresDescendingComparison(Shape *a, Shape *b)
{
    return a->sumOfSquares() > b->sumOfSquares() ;
}

#endif
