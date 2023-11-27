#include "leetcode_src/0300/307.h"
#include <gtest/gtest.h>

TEST(Test307, NormalCase)
{
    auto nums{std::vector<int>{1, 3, 5}};
    auto num_array{leetcode_307::NumArray(nums)};

    EXPECT_EQ(num_array.sumRange(0, 2), 9);
    num_array.update(1, 2);
    EXPECT_EQ(num_array.sumRange(0, 2), 8);
}