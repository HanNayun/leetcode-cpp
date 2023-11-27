#include "gtest/gtest.h"
#include "leetcode_src/0600/605.h"

TEST(Test_605, Case_0)
{
    auto solution = Leetcode_605::Solution();
    auto flowerbed = std::vector<int>{ 1, 0, 0, 0, 1 };
    auto n = 1;
    auto result = solution.canPlaceFlowers(flowerbed, n);
    EXPECT_TRUE(result);
}

TEST(Test_605, Case_1)
{
    auto solution = Leetcode_605::Solution();
    auto flowerbed = std::vector<int>{ 1, 0, 0, 0, 1 };
    auto n = 2;
    auto result = solution.canPlaceFlowers(flowerbed, n);
    EXPECT_FALSE(result);
}

TEST(Test_605, Case_2)
{
    auto solution = Leetcode_605::Solution();
    auto flowerbed = std::vector<int>{ 0 };
    auto n = 1;
    auto result = solution.canPlaceFlowers(flowerbed, n);
    EXPECT_TRUE(result);
}

TEST(Test_605, Case_3)
{
    auto solution = Leetcode_605::Solution();
    auto flowerbed = std::vector<int>{ 1, 0 };
    auto n = 1;
    auto result = solution.canPlaceFlowers(flowerbed, n);
    EXPECT_FALSE(result);
}

