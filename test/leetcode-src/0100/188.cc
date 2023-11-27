#include "gtest/gtest.h"
#include "leetcode_src/0100/188.h"

TEST(Test_188, Case_0)
{
    auto k = 2;
    auto prices = std::vector<int>{ 2, 4, 1 };
    auto expected = 2;
    auto actual = leetcode_188::Solution().maxProfit(k, prices);
    EXPECT_EQ(expected, actual);
}

TEST(Test_188, Case_1)
{
    auto k = 2;
    auto prices = std::vector<int>{ 3, 2, 6, 5, 0, 3 };
    auto expected = 7;
    auto actual = leetcode_188::Solution().maxProfit(k, prices);
    EXPECT_EQ(expected, actual);
}

TEST(Test_188, Case_2)
{
    auto k = 4;
    auto prices = std::vector<int>{ 99, 97, 84, 74, 66, 61, 54, 32, 12, 10, 9, 4, 3, 1 };
    auto expected = 0;
    auto actual = leetcode_188::Solution().maxProfit(k, prices);
    EXPECT_EQ(expected, actual);
}