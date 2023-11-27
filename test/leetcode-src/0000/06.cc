#include "leetcode_src/0000/06.h"

#include <gtest/gtest.h>

TEST(Test06, Case0)
{
    auto solution{leetcode_06::Solution{}};
    auto input{"PAYPALISHIRING"};
    auto result{solution.convert(input, 3)};
    EXPECT_EQ(result, "PAHNAPLSIIGYIR");
}

TEST(Test06, Case1)
{
    auto solution{leetcode_06::Solution{}};
    auto input{"PAYPALISHIRING"};
    auto result{solution.convert(input, 4)};
    EXPECT_EQ(result, "PINALSIGYAHRPI");
}

TEST(Test06, Case2)
{
    auto solution{leetcode_06::Solution{}};
    auto input{"A"};
    auto result{solution.convert(input, 4)};
    EXPECT_EQ(result, "A");
}

TEST(Test06, Case3)
{
    auto solution{leetcode_06::Solution{}};
    auto input{"AB"};
    auto result{solution.convert(input, 4)};
    EXPECT_EQ(result, "AB");
}

TEST(Test06, OneRowCase)
{
    auto solution{leetcode_06::Solution{}};
    auto input{"AB"};
    auto result{solution.convert(input, 1)};
    EXPECT_EQ(result, "AB");
}