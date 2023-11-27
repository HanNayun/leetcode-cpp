#include "leetcode_src/2700/2760.h"
#include <gtest/gtest.h>

TEST(Test2760, NormalCase)
{
    auto solution{leetcode_2760::Solution{}};
    auto nums{std::vector<int>{3, 2, 5, 4}};
    auto threshold{5};
    auto expected{3};
    EXPECT_EQ(solution.longestAlternatingSubarray(nums, threshold), expected);

    nums = std::vector<int>{1, 2};
    threshold = 2;
    expected = 1;
    EXPECT_EQ(solution.longestAlternatingSubarray(nums, threshold), expected);

    nums = std::vector<int>{2, 3, 4, 5};
    threshold = 4;
    expected = 3;
    EXPECT_EQ(solution.longestAlternatingSubarray(nums, threshold), expected);

    nums = std::vector<int>{2, 2};
    threshold = 18;
    expected = 1;
    EXPECT_EQ(solution.longestAlternatingSubarray(nums, threshold), expected);

    nums = std::vector<int>{2, 2, 5, 1, 6, 7, 8};
    threshold = 17;
    expected = 3;
    EXPECT_EQ(solution.longestAlternatingSubarray(nums, threshold), expected);

    nums = std::vector<int>{4, 4, 4};
    threshold = 8;
    expected = 1;
    EXPECT_EQ(solution.longestAlternatingSubarray(nums, threshold), expected);

    nums = std::vector<int>{4};
    threshold = 1;
    expected = 0;
    EXPECT_EQ(solution.longestAlternatingSubarray(nums, threshold), expected);
}