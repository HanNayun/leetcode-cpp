#include "leetcode_src/1400/1465.h"
#include "gtest/gtest.h"

TEST(test_1465, case_0)
{
    auto solution{ Leetcode_1465::Solution() };
    auto h{ 5 };
    auto w{ 4 };
    auto horizontal_cuts{ std::vector<int>{ 1, 2, 4 }};
    auto vertical_cuts{ std::vector<int>{ 1, 3 }};
    auto expected{ 4 };
    EXPECT_EQ(expected, solution.maxArea(h, w, horizontal_cuts, vertical_cuts));
}

TEST(test_1465, case_1)
{
    auto solution{ Leetcode_1465::Solution() };
    auto h{ 5 };
    auto w{ 4 };
    auto horizontal_cuts{ std::vector<int>{ 3, 1 }};
    auto vertical_cuts{ std::vector<int>{ 1, }};
    auto expected{ 6 };
    EXPECT_EQ(expected, solution.maxArea(h, w, horizontal_cuts, vertical_cuts));
}

TEST(test_1465, case_2)
{
    auto solution{ Leetcode_1465::Solution() };
    auto h{ 5 };
    auto w{ 4 };
    auto horizontal_cuts{ std::vector<int>{ 3 }};
    auto vertical_cuts{ std::vector<int>{ 3 }};
    auto expected{ 9 };
    EXPECT_EQ(expected, solution.maxArea(h, w, horizontal_cuts, vertical_cuts));
}

TEST(test_1465, overflow_int)
{
    auto solution{ Leetcode_1465::Solution() };
    auto h{ 1000000000 };
    auto w{ 1000000000 };
    auto horizontal_cuts{ std::vector<int>{ 2 }};
    auto vertical_cuts{ std::vector<int>{ 2 }};
    auto expected{ 81 };
    EXPECT_EQ(expected, solution.maxArea(h, w, horizontal_cuts, vertical_cuts));
}