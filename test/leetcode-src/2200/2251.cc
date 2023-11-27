#include "leetcode_src/2200/2251.h"

#include "gtest/gtest.h"

TEST(Test_2251, Case_0)
{
    auto solution = Leetcode_2251::Solution();

    auto flowers = std::vector<std::vector<int>>{{ 1, 6 },
                                                 { 3, 7 },
                                                 { 9, 12 },
                                                 { 4, 13 }};

    auto people = std::vector<int>{ 2, 3, 7, 11 };

    auto expected = std::vector<int>{ 1, 2, 2, 2 };
    auto result = solution.fullBloomFlowers(flowers, people);
    EXPECT_EQ(expected, result);
}

TEST(Test_2251, Case_1)
{
    auto solution = Leetcode_2251::Solution();

    auto flowers = std::vector<std::vector<int>>{{ 1, 10 },
                                                 { 3, 3 }};

    auto people = std::vector<int>{ 3, 3, 2 };

    auto expected = std::vector<int>{ 2, 2, 1 };
    auto result = solution.fullBloomFlowers(flowers, people);
    EXPECT_EQ(expected, result);
}