#include "leetcode_src/2200/2258.h"
#include <gtest/gtest.h>

TEST(Test2258, NormalCase)
{
    auto solution{ leetcode_2258::Solution() };

    auto input{ std::vector<std::vector<int>>{
            { 0, 2, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 2, 2, 1, 0 },
            { 0, 2, 0, 0, 1, 2, 0 },
            { 0, 0, 2, 2, 2, 0, 2 },
            { 0, 0, 0, 0, 0, 0, 0 },
    }};
    EXPECT_EQ(solution.maximumMinutes(input), 3);

    input = std::vector<std::vector<int>>{
            { 0, 0, 0, 0 },
            { 0, 1, 2, 0 },
            { 0, 2, 0, 0 },
    };
    EXPECT_EQ(solution.maximumMinutes(input), +leetcode_2258::Solution::kImpossible);

    input = std::vector<std::vector<int>>{
            { 0, 0, 0 },
            { 2, 2, 0 },
            { 1, 2, 0 },
    };
    EXPECT_EQ(solution.maximumMinutes(input), +leetcode_2258::Solution::kAlwaysSafe);
}