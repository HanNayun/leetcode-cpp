#include "leetcode_src/0000/01.h"

#include <gtest/gtest.h>

TEST(Test_01, Case_0)
{
    leetcode_1::Solution solution;
    std::vector<int> nums{2, 7, 11, 15};
    int target{9};

    auto result = solution.twoSum(nums, target);
    auto expected = std::vector<int>{0, 1};
    EXPECT_EQ(result, expected);
}

TEST(Test_01, Case_1)
{
    leetcode_1::Solution solution;
    std::vector<int> nums{3, 2, 4};
    int target{6};

    auto result = solution.twoSum(nums, target);
    auto expected = std::vector<int>{1, 2};
    EXPECT_EQ(result, expected);
}

TEST(Test_01, Case_2)
{
    leetcode_1::Solution solution;
    std::vector<int> nums{3, 3};
    int target{6};

    auto result = solution.twoSum(nums, target);
    auto expected = std::vector<int>{0, 1};
    EXPECT_EQ(result, expected);
}

TEST(Test_01, not_find)
{
    leetcode_1::Solution solution;
    std::vector<int> nums{4, 3};
    int target{6};

    auto result = solution.twoSum(nums, target);
    auto expected = std::vector<int>{};
    EXPECT_EQ(result, expected);
}