#include "leetcode_src/0000/16.h"

#include <gtest/gtest.h>

TEST(Test16, NormalCase)
{
    auto solution{ leetcode_16::Solution() };

    auto input{ std::vector<int>{ -1, 2, 1, -4 }};
    EXPECT_EQ(solution.threeSumClosest(input, 1), 2);

    input = { 1, 1, 1, 0 };
    EXPECT_EQ(solution.threeSumClosest(input, -100), 2);

    input = { 0, 0, 0 };
    EXPECT_EQ(solution.threeSumClosest(input, 1), 0);
}