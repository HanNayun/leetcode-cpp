#include "leetcode_src/0000/05.h"

#include <gtest/gtest.h>

TEST(Test05, NormalCase)
{
    auto solution{leetcode_05::Solution{}};
    auto input{"babad"};
    auto result{solution.longestPalindrome(input)};
    EXPECT_EQ(result, "bab");
}

TEST(Test05, NormalCas1)
{
    auto solution{leetcode_05::Solution{}};
    auto input{"cbbd"};
    auto result{solution.longestPalindrome(input)};
    EXPECT_EQ(result, "bb");
}

TEST(Test05, NormalCas2)
{
    auto solution{leetcode_05::Solution{}};
    auto input{"bb"};
    auto result{solution.longestPalindrome(input)};
    EXPECT_EQ(result, "bb");
}

TEST(Test05, EmptyInput)
{
    auto solution{leetcode_05::Solution{}};
    auto input{""};
    auto result{solution.longestPalindrome(input)};
    EXPECT_EQ(result, "");
}

TEST(Test05, OneLettry)
{
    auto solution{leetcode_05::Solution{}};
    auto input{"abcedfa"};
    auto result{solution.longestPalindrome(input)};
    EXPECT_EQ(result, "a");
}