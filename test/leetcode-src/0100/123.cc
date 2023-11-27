#include "gtest/gtest.h"
#include "leetcode_src/0100/123.h"

TEST(Test_123, Case_0)
{
    auto prices = std::vector<int>{ 3, 3, 5, 0, 0, 3, 1, 4 };
    auto actual = Leetcode_123::Solution().maxProfit(prices);
    EXPECT_EQ(6, actual);
}

TEST(Test_123, Case_1)
{
    auto prices = std::vector<int>{ 1, 2, 3, 4, 5 };
    auto actual = Leetcode_123::Solution().maxProfit(prices);
    EXPECT_EQ(4, actual);
}

TEST(Test_123, Case_2)
{
    auto prices = std::vector<int>{ 7, 6, 4, 3, 1 };
    auto actual = Leetcode_123::Solution().maxProfit(prices);
    EXPECT_EQ(0, actual);
}