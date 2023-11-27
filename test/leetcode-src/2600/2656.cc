#include "leetcode_src/2600/2656.h"
#include <gtest/gtest.h>

TEST(LeetCode2656Solution, ReturnsCorrectMaximizedSum)
{
    leetcode_2656::Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    int expected_maximized_sum = 18;
    EXPECT_EQ(solution.maximizeSum(nums, k), expected_maximized_sum);

    nums = {5, 5, 5};
    k = 2;
    expected_maximized_sum = 11;
    EXPECT_EQ(solution.maximizeSum(nums, k), expected_maximized_sum);
}
