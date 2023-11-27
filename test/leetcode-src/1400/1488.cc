#include "leetcode_src/1400/1488.h"

#include "gtest/gtest.h"

TEST(Test_1488, Case_0)
{
    Leetcode_1488::Solution solution;

    std::vector<int> input{ 0, 1, 1 };
    std::vector<int> expected{};
    EXPECT_EQ(expected, solution.avoidFlood(input));

    input = { 1, 2, 3, 4 };
    expected = { -1, -1, -1, -1 };
    EXPECT_EQ(expected, solution.avoidFlood(input));

    input = { 1, 2, 0, 0, 2, 1 };
    expected = { -1, -1, 2, 1, -1, -1 };
    EXPECT_EQ(expected, solution.avoidFlood(input));

    input = { 1, 2, 0, 1, 2 };
    expected = {};
    EXPECT_EQ(expected, solution.avoidFlood(input));
}