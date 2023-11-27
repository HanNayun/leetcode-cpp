#include "leetcode_src/0400/421.h"
#include "gtest/gtest.h"

TEST(Test421, NormalCase)
{
    leetcode_421::Solution solution;

    std::vector<int> nums{ 3, 10, 5, 25, 2, 8 };
    ASSERT_EQ(solution.findMaximumXOR(nums), 28);

    nums = { 14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70 };
    ASSERT_EQ(solution.findMaximumXOR(nums), 127);
}