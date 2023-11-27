#include "leetcode_src/0900/907.h"
#include <gtest/gtest.h>

TEST(Test907, NormalCase)
{
    auto solution{leetcode_907::Solution()};

    auto input{std::vector<int>{11, 81, 94, 43, 3}};
    EXPECT_EQ(solution.sumSubarrayMins(input), 444);

    input = {3, 1, 2, 4};
    EXPECT_EQ(solution.sumSubarrayMins(input), 17);
}