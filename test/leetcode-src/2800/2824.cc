#include "leetcode_src/2800/2824.h"
#include <gtest/gtest.h>

TEST(Test2824, NormalCase)
{
    auto solution{leetcode_2824::Solution()};
    auto nums{std::vector<int>{-1, 1, 2, 3, 1}};
    EXPECT_EQ(solution.countPairs(nums, 2), 3);

    nums = {-6, 2, 5, -2, -7, -1, 3};
    EXPECT_EQ(solution.countPairs(nums, -2), 10);
}