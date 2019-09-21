#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/sort.h"
#include "../src/circular_sector.h"
#include "../src/triangle.h"
#include "../src/ellipse.h"
#include "../test/ut_sort.h"
#include <algorithm>
#include <vector>

template<class F> void g(F f) { f(); }

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST (ShapeTest , first)
{
    ASSERT_TRUE(true);
}
TEST (ShapeTest , Triangle)
{
    Triangle t( 0, 0, 3, 0, 3, 4);

    ASSERT_EQ(false , t.isIsoscelesTriangle() );
    ASSERT_NEAR(12, t.perimeter() , 0.001 );
    ASSERT_NEAR(6 , t.area() , 0.001 );
    ASSERT_NEAR(180 , t.sumOfSquares() , 0.001 ); //New Line
}
TEST (ShapeTest , Ellipse)
{
    Ellipse e(4,3);
    ASSERT_NEAR(37.6991 , e.area() , 0.001 );
    ASSERT_NEAR(22.8495 , e.perimeter() , 0.001 );
    ASSERT_NEAR(1943.3217 , e.sumOfSquares() , 0.1 );  // New Line
}
TEST (ShapeTest , CircularSector)
{
    CircularSector c(1, 90);
    ASSERT_NEAR(0.78539 , c.area() , 0.001 );
    ASSERT_NEAR(3.57079 , c.perimeter() , 0.001 );
    ASSERT_NEAR(13.36737 , c.sumOfSquares() , 0.001 ); //New Line
}
