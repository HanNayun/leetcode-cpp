#include "leetcode_src/1300/1333.h"

#include "gtest/gtest.h"

TEST(Test_1333, Case_0)
{
    auto solution = Leetcode_1333::Solution();

    auto restsurants = std::vector<std::vector<int>>{
            { 1, 4,  1, 40, 10 },
            { 2, 8,  0, 50, 5 },
            { 3, 8,  1, 30, 4 },
            { 4, 10, 0, 10, 3 },
            { 5, 1,  1, 15, 1 }
    };

    auto vegan_friendly = 1;
    auto max_price = 50;
    auto max_distance = 10;

    auto expected = std::vector<int>{ 3, 1, 5 };
    auto result = solution.filterRestaurants(restsurants, vegan_friendly, max_price, max_distance);
    EXPECT_EQ(expected, result);
}

TEST(Test_1333, Case_1)
{
    auto solution = Leetcode_1333::Solution();

    auto restsurants = std::vector<std::vector<int>>{
            { 1, 4,  1, 40, 10 },
            { 2, 8,  0, 50, 5 },
            { 3, 8,  1, 30, 4 },
            { 4, 10, 0, 10, 3 },
            { 5, 1,  1, 15, 1 }
    };

    auto vegan_friendly = 0;
    auto max_price = 50;
    auto max_distance = 10;

    auto expected = std::vector<int>{ 4, 3, 2, 1, 5 };
    auto result = solution.filterRestaurants(restsurants, vegan_friendly, max_price, max_distance);
    EXPECT_EQ(expected, result);
}