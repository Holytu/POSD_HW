#ifndef UT_SORT_H
#define UT_SORT_H
#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/sort.h"
#include "../src/circular_sector.h"
#include "../src/triangle.h"
#include "../src/ellipse.h"
#include "../test/ut_sort.h"
#include "../src/terminal.h"
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

/*TEST (SortTest , Tr)
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

    //ASSERT_TRUE(true);
} */
/*TEST(SortTest , Sorting)
{

    vector<Shape*> p = {new Ellipse(4,3) , new Ellipse(5,4) , new CircularSector(1,300) , new Triangle(0, 0, 3, 0, 3, 4) };

    Sort SortClass(&p);

    SortClass->sortArea();

    ASSERT_NEAR(2.61799 , p[0]->area() , 0.01 );
    ASSERT_NEAR(6 , p[1]->area() , 0.01 );
    ASSERT_NEAR(37.6991 , p[2]->area() , 0.01 );
    ASSERT_NEAR(62.8319 , p[3]->area() , 0.01 );

    SortClass->sortPerimeter();

    ASSERT_NEAR(7.23599 , p[0]->perimeter() , 0.01 );
    ASSERT_NEAR(12 , p[1]->perimeter() , 0.01 );
    ASSERT_NEAR(22.8496 , p[2]->perimeter() , 0.01 );
    ASSERT_NEAR(29.1327 , p[3]->perimeter() , 0.01 );

    SortClass->sortSumOfSquares();

    ASSERT_NEAR(59.2134 , p[0]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(180 , p[1]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(1943.33 , p[2]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(4796.56 , p[3]->sumOfSquares() , 0.01 );

} */
/*TEST(SortTest , AscComp_area)
{
    vector<Shape*> p = {new Ellipse(4,3) , new Ellipse(5,4) , new CircularSector(1,300) , new Triangle(0, 0, 3, 0, 3, 4) };

    Sort* SortClass = new Sort(&p);

    DescendingComparison dsc("area");
    SortClass->sortArea(dsc);

    ASSERT_NEAR(2.61799 , p[3]->area() , 0.001 );
    ASSERT_NEAR(6 , p[2]->area() , 0.001 );
    ASSERT_NEAR(37.6991 , p[1]->area() , 0.001 );
    ASSERT_NEAR(62.8319 , p[0]->area() , 0.001 );

    SortClass->sortArea(areaAscendingComparison);
    ASSERT_NEAR(2.61799 , p[0]->area() , 0.01 );
    ASSERT_NEAR(6 , p[1]->area() , 0.01 );
    ASSERT_NEAR(37.6991 , p[2]->area() , 0.01 );
    ASSERT_NEAR(62.8319 , p[3]->area() , 0.01 );

    SortClass->sortArea([](Shape *a, Shape *b) {
            return a->sumOfSquares() < b->sumOfSquares();
    });
    ASSERT_NEAR(2.61799 , p[0]->area() , 0.01 );
    ASSERT_NEAR(6 , p[1]->area() , 0.01 );
    ASSERT_NEAR(37.6991 , p[2]->area() , 0.01 );
    ASSERT_NEAR(62.8319 , p[3]->area() , 0.01 );
}*/
/*TEST(SortTest , AscComp_perimeter)
{
    vector<Shape*> p = {new Ellipse(4,3) , new Ellipse(5,4) , new CircularSector(1,300) , new Triangle(0, 0, 3, 0, 3, 4) };

    Sort* SortClass = new Sort(&p);

    AscendingComparison asc("perimeter");
    SortClass->sortPerimeter(asc);
    ASSERT_NEAR(7.23599 , p[0]->perimeter() , 0.01 );
    ASSERT_NEAR(12 , p[1]->perimeter() , 0.01 );
    ASSERT_NEAR(22.8496 , p[2]->perimeter() , 0.01 );
    ASSERT_NEAR(29.1327 , p[3]->perimeter() , 0.01 );

    SortClass->sortPerimeter(perimeterAscendingComparison);
    ASSERT_NEAR(7.23599 , p[0]->perimeter() , 0.01 );
    ASSERT_NEAR(12 , p[1]->perimeter() , 0.01 );
    ASSERT_NEAR(22.8496 , p[2]->perimeter() , 0.01 );
    ASSERT_NEAR(29.1327 , p[3]->perimeter() , 0.01 );

    SortClass->sortPerimeter([](Shape *a, Shape *b) {
            return a->perimeter() < b->perimeter();
    });
    ASSERT_NEAR(7.23599 , p[0]->perimeter() , 0.01 );
    ASSERT_NEAR(12 , p[1]->perimeter() , 0.01 );
    ASSERT_NEAR(22.8496 , p[2]->perimeter() , 0.01 );
    ASSERT_NEAR(29.1327 , p[3]->perimeter() , 0.01 );
}*/
/*TEST(SortTest , AscComp_sumOfSquares)
{
    vector<Shape*> p = {new Ellipse(4,3) , new Ellipse(5,4) , new CircularSector(1,300) , new Triangle(0, 0, 3, 0, 3, 4) };

    Sort* SortClass = new Sort(&p);

    AscendingComparison asc("sumOfSquares");
    SortClass->sortSumOfSquares(asc);
    ASSERT_NEAR(59.2134 , p[0]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(180 , p[1]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(1943.33 , p[2]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(4796.56 , p[3]->sumOfSquares() , 0.01 );

    SortClass->sortSumOfSquares(sumOfSquaresAscendingComparison);
    ASSERT_NEAR(59.2134 , p[0]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(180 , p[1]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(1943.33 , p[2]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(4796.56 , p[3]->sumOfSquares() , 0.01 );

    SortClass->sortSumOfSquares([](Shape *a, Shape *b) {
            return a->sumOfSquares() < b->sumOfSquares();
    });
    ASSERT_NEAR(59.2134 , p[0]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(180 , p[1]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(1943.33 , p[2]->sumOfSquares() , 0.01 );
    ASSERT_NEAR(4796.56 , p[3]->sumOfSquares() , 0.01 );

}*/
/*TEST(SortTest , AscComp_QuickSort)
{

    vector<Shape*> p = {new Ellipse(4,3) , new Ellipse(5,4) , new CircularSector(1,300) , new Triangle(0, 0, 3, 0, 3, 4) ,
        new CircularSector(4, 90) , new Triangle(0, 0, 9, 0, 9, 12) };

    Sort* SortClass = new Sort(&p);
    AscendingComparison asc("area");
    SortClass->quickSort(asc);
    ASSERT_NEAR(2.61799 , p[0]->area(), 0.01 );
    ASSERT_NEAR(6.00000 , p[1]->area(), 0.01 );
    ASSERT_NEAR(12.5664 , p[2]->area(), 0.01 );
    ASSERT_NEAR(37.6991 , p[3]->area(), 0.01 );
    ASSERT_NEAR(54.0000 , p[4]->area(), 0.01 );
    ASSERT_NEAR(62.8319 , p[5]->area(), 0.01 );


    DescendingComparison dsc("sumOfSquares");
    SortClass->quickSort(dsc);

    ASSERT_NEAR(4796.56 , p[0]->sumOfSquares(), 0.01 );
    ASSERT_NEAR(4212 , p[1]->sumOfSquares(), 0.01 );
    ASSERT_NEAR(361.923 , p[2]->sumOfSquares(), 0.01 );
    ASSERT_NEAR(1943.33 , p[3]->sumOfSquares(), 0.01 );
    ASSERT_NEAR(180 , p[4]->sumOfSquares(), 0.01 );
    ASSERT_NEAR(59.2134 , p[5]->sumOfSquares(), 0.01 );

}*/
/*
TEST(TerminalTest , Example)
{
    Terminal * test = new Terminal("Triangle (-2,0,0,3,2,0) Triangle (-2,0,0,6,2,0) area dec");
    ASSERT_EQ("[12.000000, 6.000000]", test->showResult());
}
*/

TEST(TerminalTest , AreaDec)
{

    /*Terminal *test = new Terminal("Ellipse(6,5) triangle(3,0,0,2,-3,0) CircularSector(8,40) area inc");
    cout << endl << "------In ut_sort.h :  -------" << endl;
    cout << test->showResult() << endl;
    cout         << "------End of function -------" << endl;
    */
    Terminal * test = new Terminal("Triangle (-2,0,0,3,2,0) Triangle (-2,0,0,6,2,0) area dec");
    ASSERT_EQ("[12.000000, 6.000000]", test->showResult());

}
TEST(TerminalTest , PerimeterAsc)
{
    Terminal * test1 = new Terminal("Ellipse (6,5) Triangle (3,0,0,2,-3,0) CircularSector (8,40) perimeter inc");
    ASSERT_EQ("[13.211103, 21.585054, 35.415927]", test1->showResult());
}
TEST(TerminalTest , SumofSquaresAsc)
{
    Terminal * test2 = new Terminal("Ellipse (10,8) Triangle (3,0,0,4,-3,0) Triangle (6,0,0,4,-6,0) CircularSector (5,60) sumOfSquares inc");
    //cout << test2->showResult() << endl;
    ASSERT_EQ("[400.000000, 403.482622, 1274.132922, 66560.334613]", test2->showResult());
}
TEST(TerminalTest , Exc)
{
    Terminal * test3 = new Terminal("Ellipse (10,8) Triangle (3,0,0,4,-3,0) Triangle (6,0,0,4,-6,0) CircularSector (5,60) perimeter inc");
    ASSERT_EQ("[15.235988, 16.000000, 26.422205, 58.265482]",test3->showResult() );

    Terminal * test4 = new Terminal("Ellipse (10,8) Triangle (3,0,0,4,-3,0) Triangle (6,0,0,4,-6,0) CircularSector (5,60) perimeter");
    try
    {
        test4->showResult();
    }
    catch(const string str)
    {
        ASSERT_EQ("Unuseful User Input!", str);
    }
}
TEST(TerminalTest , Try)
{
    Terminal * test5 = new Terminal("Ellipse (10    ,8) Triangle (3,0,0,4,-3 ,0) Triangle (3,0,0,4,    -3,0) !@#$%% Triangle (6,0,    0,4,-6,0) CircularSector (5,60) perimeter dec !@#$%%");
    ASSERT_EQ("[58.265482, 26.422205, 16.000000, 16.000000, 15.235988]", test5->showResult() );
}
TEST(TerminalTest , input)
{
    string str = "";
    ifstream ifs;
    ifs.open("input.txt", ios::in);
    if( ifs.is_open() )
    {
        getline(ifs, str, '\n');
    }
    ifs.close();
    ASSERT_EQ("Ellipse (9,8) Triangle (0,0,5,0,0,5) CircularSector (9, 35)", str);
}
TEST(TerminalTest , output)
{
    string wo = "Testing";
    ofstream of;
    of.open("output.txt", ios::out);
    if(of.is_open() )
        of << wo;
    of.close();

    string str = "";
    ifstream ifs;
    ifs.open("output.txt", ios::in);
    if(ifs.is_open() )
        getline(ifs, str, '\n');
    ifs.close();
    ASSERT_EQ("Testing", str);
}
#endif
