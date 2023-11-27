#include "gtest/gtest.h"
#include "leetcode_src/0100/122.h"

TEST(Test_122, Case_0)
{
    auto solution = Leetcode_122::Solution();
    auto prices = std::vector<int>{ 7, 1, 5, 3, 6, 4 };
    auto result = solution.maxProfit(prices);
    EXPECT_EQ(result, 7);
}

TEST(Test_122, Case_1)
{
    auto solution = Leetcode_122::Solution();
    auto prices = std::vector<int>{ 1, 2, 3, 4, 5 };
    auto result = solution.maxProfit(prices);
    EXPECT_EQ(result, 4);
}

TEST(Test_122, Case_2)
{
    auto solution = Leetcode_122::Solution();
    auto prices = std::vector<int>{ 7, 6, 4, 3, 1 };
    auto result = solution.maxProfit(prices);
    EXPECT_EQ(result, 0);
}
