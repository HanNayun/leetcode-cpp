#include "leetcode_src/0700/765.h"
#include <gtest/gtest.h>

TEST(Test765, NormalCase)
{
    auto solution{ leetcode_765::Solution{}};

    auto row{ std::vector<int>{ 0, 2, 1, 3 }};
    EXPECT_EQ(solution.minSwapsCouples(row), 1);

    row = std::vector<int>{ 3, 2, 0, 1 };
    EXPECT_EQ(solution.minSwapsCouples(row), 0);

    row = std::vector<int>{ 10, 7, 4, 2, 3, 0, 9, 11, 1, 5, 6, 8 };
    EXPECT_EQ(solution.minSwapsCouples(row), 4);
}