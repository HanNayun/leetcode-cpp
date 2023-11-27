#include "leetcode_src/1700/1726.h"

#include "gtest/gtest.h"

TEST(test_1762, case_0)
{
    auto input = std::vector<int>{ 2, 3, 4, 6 };
    auto expected{ 8 };
    auto actual{ Leetcode_1726::Solution{}.tupleSameProduct(input) };
    EXPECT_EQ(actual, expected);
}

TEST(test_1762, case_1)
{
    auto input = std::vector<int>{ 1, 2, 4, 5, 10 };
    auto expected{ 16 };
    auto actual{ Leetcode_1726::Solution{}.tupleSameProduct(input) };
    EXPECT_EQ(actual, expected);
}