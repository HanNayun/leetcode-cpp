#include "leetcode_src/0300/300.h"

#include "gtest/gtest.h"

TEST(Test_300, Case_0)
{
    auto nums{ std::vector<int>{ 1, 3, 6, 7, 9, 4, 10, 5, 6 }};
    auto expected{ 6 };
    auto solution{ Leetcode_300::Solution() };
    EXPECT_EQ(solution.lengthOfLIS(nums), expected);
}

TEST(Test_300, Case_1)
{
    auto nums{ std::vector<int>{ 10, 9, 2, 5, 3, 7, 101, 18 }};
    auto expected{ 4 };
    auto solution{ Leetcode_300::Solution() };
    EXPECT_EQ(solution.lengthOfLIS(nums), expected);
}

TEST(Test_300, Case_2)
{
    auto nums{ std::vector<int>{ 0, 1, 0, 3, 2, 3 }};
    auto expected{ 4 };
    auto solution{ Leetcode_300::Solution() };
    EXPECT_EQ(solution.lengthOfLIS(nums), expected);
}