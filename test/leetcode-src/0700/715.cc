#include "leetcode_src/0700/715.h"
#include <gtest/gtest.h>

TEST(Test715, NormalCase)
{
    auto solution{leetcode_715::RangeModule{}};

    solution.addRange(10, 20);
    solution.removeRange(14, 16);
    EXPECT_TRUE(solution.queryRange(10, 14));
    EXPECT_FALSE(solution.queryRange(13, 15));
    EXPECT_TRUE(solution.queryRange(16, 17));
}