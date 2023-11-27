#include "leetcode_src/2100/2136.h"

#include "gtest/gtest.h"

TEST(Test_2136, Case_0)
{
    auto solution = Leetcode_2136::Solution();
    auto plant_time = std::vector<int>{ 1, 4, 3 };
    auto grow_time = std::vector<int>{ 2, 3, 1 };
    auto result = solution.earliestFullBloom(plant_time, grow_time);
    EXPECT_EQ(result, 9);
}

TEST(Test_2136, Case_1)
{
    auto solution = Leetcode_2136::Solution();
    auto plant_time = std::vector<int>{ 1, 2, 3, 2 };
    auto grow_time = std::vector<int>{ 2, 1, 2, 1 };
    auto result = solution.earliestFullBloom(plant_time, grow_time);
    EXPECT_EQ(result, 9);
}