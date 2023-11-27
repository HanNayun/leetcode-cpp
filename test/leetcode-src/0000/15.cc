#include "leetcode_src/0000/15.h"
#include <gtest/gtest.h>

TEST(Test15, NormalCase)
{
    auto solution{ leetcode_15::Solution{}};

    auto input{ std::vector<int>{ -1, 0, 1, 2, -1, -4 }};
    auto expected{ std::vector<std::vector<int>>{{ -1, -1, 2 },
                                                 { -1, 0,  1 }}};
    EXPECT_EQ(solution.threeSum(input), expected);

    input = { 0, 1, 1 };
    expected = {};
    EXPECT_EQ(solution.threeSum(input), expected);

    input = { 0, 0, 0 };
    expected = {{ 0, 0, 0 }};
    EXPECT_EQ(solution.threeSum(input), expected);
}