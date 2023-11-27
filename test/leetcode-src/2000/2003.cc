#include "leetcode_src/2000/2003.h"

#include "gtest/gtest.h"

TEST(Test2003, NormalCases)
{
    auto solution{ Leetcode_2003::Solution() };

    auto parents{ std::vector<int>{ -1, 0, 0, 2 }};
    auto nums{ std::vector<int>{ 1, 2, 3, 4 }};
    auto expect{ std::vector<int>{ 5, 1, 1, 1 }};
    auto result{ solution.smallestMissingValueSubtree(parents, nums) };
    EXPECT_EQ(result, expect);

    parents = { -1, 0, 1, 0, 3, 3 };
    nums = { 5, 4, 6, 2, 1, 3 };
    expect = { 7, 1, 1, 4, 2, 1 };
    result = solution.smallestMissingValueSubtree(parents, nums);
    EXPECT_EQ(result, expect);

    parents = { -1, 2, 3, 0, 2, 4, 1 };
    nums = { 2, 3, 4, 5, 6, 7, 8 };
    expect = { 1, 1, 1, 1, 1, 1, 1 };
    result = solution.smallestMissingValueSubtree(parents, nums);
    EXPECT_EQ(result, expect);
}