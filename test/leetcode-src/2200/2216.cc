#include "leetcode_src/2200/2216.h"

#include <gtest/gtest.h>

TEST(Test2216, NormalCase)
{
    auto solution{leetcode_2216::Solution()};
    std::vector<int> nums{1, 1, 2, 3, 5};
    EXPECT_EQ(solution.minDeletion(nums), 1);

    nums = {1, 1, 2, 2, 3, 3};
    EXPECT_EQ(solution.minDeletion(nums), 2);
}