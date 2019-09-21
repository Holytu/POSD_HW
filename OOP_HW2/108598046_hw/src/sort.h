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

class AscendingComparison{
public:
    AscendingComparison(string str)
    {
        if(str == "area")
        {
            _str = str;
        }
        else if (str == "perimeter")
        {
            _str = str;
        }
        else if (str == "sumOfSquares")
        {
            _str = str;
        }
        else
        {
            _str = "";
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
/// Not Finish it!
class DescendingComparison{
public:
    DescendingComparison(string str)
    {
        if(str == "area")
        {
            _str = str;
        }
        else if (str == "perimeter")
        {
            _str = str;
        }
        else if (str == "sumOfSquares")
        {
            _str = str;
        }
        else
        {
            _str = "";
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

      void sortArea(AscendingComparison asc)
      {
          /*
          sort((*_v).begin() , (*_v).end() , [](Shape *a, Shape *b) {
              return a->area() < b->area();
          });
          */
          if(asc.getStr() == "area")
          {
            sort((*_v).begin() , (*_v).end() , areaAscendingComparison );
          }
          asc.resetStr();
      }

      void sortArea()
      {
          sort( (*_v).begin() , (*_v).end() , [](Shape *a, Shape *b) {
              return a->perimeter() < b->perimeter();
          });
      }

      void sortPerimeter()
      {
          sort((*_v).begin() , (*_v).end() , [](Shape *a, Shape *b) {
              return a->perimeter() < b->perimeter();
          });
      }

      void sortSumOfSquares()
      {
          std::sort((*_v).begin() , (*_v).end() , [](Shape *a, Shape *b) {
              return a->sumOfSquares() < b->sumOfSquares();
          });
      }
      void quickSort() // Not yet !
      {
          /*
          for ( std::vector<shape*>::iterator it = _v.begin() ; it != _v.end() ; it++ )
          {

          }
          */
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
    return b->area() < a->area() ;
}

#endif
/*
cout <<"---------------------------"<<endl;
for (vector<Shape*>::iterator iter = (*_v).begin() ; iter != (*_v).end() ; iter++)
{
    cout << (*iter)->area() << endl;
}
cout <<"---------------------------"<<endl;
*/
