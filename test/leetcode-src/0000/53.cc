#include "leetcode_src/0000/53.h"

#include <gtest/gtest.h>


TEST(Test53, NormalCase)
{
    auto solution{leetcode_53::Solution{}};
    auto nums{std::vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4}};
    auto result{solution.maxSubArray(nums)};
    EXPECT_EQ(result, 6);

    nums = std::vector<int>{1};
    result = solution.maxSubArray(nums);
    EXPECT_EQ(result, 1);

    nums = std::vector<int>{5, 4, -1, 7, 8};
    result = solution.maxSubArray(nums);
    EXPECT_EQ(result, 23);
}