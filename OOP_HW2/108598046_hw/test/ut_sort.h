#ifndef UT_SORT_H
#define UT_SORT_H
#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/sort.h"
#include "../src/circular_sector.h"
#include "../src/triangle.h"
#include "../src/ellipse.h"
#include "../test/ut_sort.h"
#include <algorithm>
#include <vector>
using namespace std;

TEST (SortTest , Tr)
{
    vector<Shape*> s = {new Ellipse(4,3) , new Ellipse(5,4) , new CircularSector(1,360) , new Triangle(0, 0, 3, 0, 3, 4) };
    vector<Shape*> *v = &s;

    cout << "----Vector data Size-----" << endl;
    cout << v->size() << endl;
    cout << "-------S area Size-------" << endl;
    for (vector<Shape*>::iterator it = s.begin() ; it != s.end() ; it++)
    {
        cout << (*it)->area() << endl;
    }
    cout << "-------V area Size-------" << endl;
    cout << (*v)[0]->area() << endl;
    cout << (*v)[1]->area() << endl;
    cout << (*v)[2]->area() << endl;
    cout << (*v)[3]->area() << endl;
    cout << "-------Iterator of V-----" << endl;
    for (vector<Shape*>::iterator iter = (*v).begin() ; iter != (*v).end() ; iter++)
    {
        cout << (*iter)->area() << endl;
    }
    cout << "-------------------------" << endl;

    ASSERT_TRUE(true);


}
TEST(SortTest , Sorting)
{
    vector<Shape*> p = {new Ellipse(4,3) , new Ellipse(5,4) , new CircularSector(1,300) , new Triangle(0, 0, 3, 0, 3, 4) };

    Sort SortClass(&p);
    /*
    SortClass.sortArea();

    ASSERT_NEAR(2.61799 , p[0]->area() , 0.01 );
    ASSERT_NEAR(6 , p[1]->area() , 0.01 );
    ASSERT_NEAR(37.6991 , p[2]->area() , 0.01 );
    ASSERT_NEAR(62.8319 , p[3]->area() , 0.01 );
    */
    SortClass.sortPerimeter();

    ASSERT_NEAR(7.23599 , p[0]->perimeter() , 0.01 );
    ASSERT_NEAR(12 , p[1]->perimeter() , 0.01 );
    ASSERT_NEAR(22.8496 , p[2]->perimeter() , 0.01 );
    ASSERT_NEAR(29.1327 , p[3]->perimeter() , 0.01 );

    SortClass.sortSumOfSquares();

    ASSERT_NEAR(59.2134 , p[0]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(180 , p[1]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(1943.33 , p[2]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(4796.56 , p[3]->sumOfSquares() , 0.01 );
}

TEST(SortTest , AscComp)
{
    vector<Shape*> p = {new Ellipse(4,3) , new Ellipse(5,4) , new CircularSector(1,300) , new Triangle(0, 0, 3, 0, 3, 4) };

    Sort* SortClass = new Sort(&p);
    AscendingComparison asc("area");
    SortClass->sortArea(asc);

    ASSERT_NEAR(2.61799 , p[0]->area() , 0.01 );
    ASSERT_NEAR(6 , p[1]->area() , 0.01 );
    ASSERT_NEAR(37.6991 , p[2]->area() , 0.01 );
    ASSERT_NEAR(62.8319 , p[3]->area() , 0.01 );

    
}

#endif
