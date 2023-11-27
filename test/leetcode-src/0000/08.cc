#include "leetcode_src/0000/08.h"
#include <gtest/gtest.h>

TEST(Test08, NormalCase)
{
    auto solution{leetcode_08::Solution()};

    EXPECT_EQ(solution.myAtoi("42"), 42);
    EXPECT_EQ(solution.myAtoi("-965"), -965);
    EXPECT_EQ(solution.myAtoi("965"), 965);
}

TEST(Test08, WithLeadingWhiteSpaceCase)
{
    auto solution{leetcode_08::Solution()};

    EXPECT_EQ(solution.myAtoi("   -42"), -42);
    EXPECT_EQ(solution.myAtoi("      +965"), 965);
}

TEST(Test08, OutOfIntRangeCase)
{
    auto solution{leetcode_08::Solution()};

    EXPECT_EQ(solution.myAtoi("99999999999999999999999999"), INT32_MAX);
    EXPECT_EQ(solution.myAtoi("-9999999999999999999999999999"), INT32_MIN);
    EXPECT_EQ(solution.myAtoi("-91283472332"), INT32_MIN);
}

TEST(Test08, WithPostNoNumberPartCase)
{
    auto solution{leetcode_08::Solution()};

    EXPECT_EQ(solution.myAtoi("999999999999999999999999992fasdf"), INT32_MAX);
    EXPECT_EQ(solution.myAtoi("-9999999999999999999999999999fadfa"), INT32_MIN);
    EXPECT_EQ(solution.myAtoi("-99a999999999"), -99);
}

TEST(Test08, NoIntegerCase)
{
    auto solution{leetcode_08::Solution()};

    EXPECT_EQ(solution.myAtoi("a999999999999999999999999992fasdf"), 0);
    EXPECT_EQ(solution.myAtoi("-a9999999999999999999999999999fadfa"), 0);
    EXPECT_EQ(solution.myAtoi("-a99a999999999"), 0);
}

