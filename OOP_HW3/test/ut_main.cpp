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

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
