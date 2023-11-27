#include "leetcode_src/0000/11.h"

#include <gtest/gtest.h>

TEST(Test11, NormalCase)
{
    auto solution{leetcode_11::Solution()};
    auto height{std::vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7}};
    EXPECT_EQ(solution.maxArea(height), 49);

    height = {1, 1};
    EXPECT_EQ(solution.maxArea(height), 1);
}