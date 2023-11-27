#include "leetcode_src/0000/20.h"

#include <gtest/gtest.h>

TEST(Test20, NormalCase)
{
    auto solution{leetcode_20::Solution()};
    auto input{"()"};
    auto result{solution.isValid(input)};
    EXPECT_EQ(result, true);

    input = "()[]{}";
    result = solution.isValid(input);
    EXPECT_EQ(result, true);

    input = "(]";
    result = solution.isValid(input);
    EXPECT_EQ(result, false);
}