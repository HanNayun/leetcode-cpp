#include "leetcode_src/0000/07.h"

#include <gtest/gtest.h>

TEST(Test07, NormalCase)
{
    auto input{123};
    auto result{leetcode_07::Solution{}.reverse(input)};
    EXPECT_EQ(result, 321);
}

TEST(Test07, NegtiveCase)
{
    auto input{-123};
    auto result{leetcode_07::Solution{}.reverse(input)};
    EXPECT_EQ(result, -321);
}

TEST(Test07, OverflowCase)
{
    auto input{1534236469};
    auto result{leetcode_07::Solution{}.reverse(input)};
    EXPECT_EQ(result, 0);
}