#include "leetcode_src/0000/18.h"
#include <gtest/gtest.h>

TEST(Test18, NormalCase)
{
    auto solution{leetcode_18::Solution{}};
    auto nums{std::vector<int>{1, 0, -1, 0, -2, 2}};
    auto target{0};
    auto expected{std::vector<std::vector<int>>{
            {-2, -1, 1, 2},
            {-2, 0,  0, 2},
            {-1, 0,  0, 1}
    }};
    EXPECT_EQ(solution.fourSum(nums, target), expected);

    nums = {2, 2, 2, 2, 2};
    target = 8;
    expected = {{2, 2, 2, 2}};
    EXPECT_EQ(solution.fourSum(nums, target), expected);

    nums = {-2, -1, -1, 1, 1, 2, 2};
    target = 0;
    expected = {{-2, -1, 1, 2},
                {-1, -1, 1, 1}};
    EXPECT_EQ(solution.fourSum(nums, target), expected);

    nums = {1000000000, 1000000000, 1000000000, 1000000000};
    target = 0;
    expected = {};
    EXPECT_EQ(solution.fourSum(nums, target), expected);
}