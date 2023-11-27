#include "leetcode_src/0000/03.h"

#include <gtest/gtest.h>

TEST(test_03, case_0)
{
    auto s{"abcabcbb"};
    auto solution{leetcode_03::Solution{}};
    auto result{solution.lengthOfLongestSubstring(s)};
    EXPECT_EQ(result, 3);
}

TEST(test_03, case_1)
{
    auto s{"bbbbb"};
    auto solution{leetcode_03::Solution{}};
    auto result{solution.lengthOfLongestSubstring(s)};
    EXPECT_EQ(result, 1);
}

TEST(test_03, case_2)
{
    auto s{"pwwkew"};
    auto solution{leetcode_03::Solution{}};
    auto result{solution.lengthOfLongestSubstring(s)};
    EXPECT_EQ(result, 3);
}

TEST(test_03, case_3)
{
    auto s{"aab"};
    auto solution{leetcode_03::Solution{}};
    auto result{solution.lengthOfLongestSubstring(s)};
    EXPECT_EQ(result, 2);
}

TEST(test_03, case_4)
{
    auto s{""};
    auto solution{leetcode_03::Solution{}};
    auto result{solution.lengthOfLongestSubstring(s)};
    EXPECT_EQ(result, 0);
}

TEST(test_03, case_5)
{
    auto s{"abba"};
    auto solution{leetcode_03::Solution{}};
    auto result{solution.lengthOfLongestSubstring(s)};
    EXPECT_EQ(result, 2);
}

TEST(test_03, case_6)
{
    auto s{"tmmzuxt"};
    auto solution{leetcode_03::Solution{}};
    auto result{solution.lengthOfLongestSubstring(s)};
    EXPECT_EQ(result, 5);
}

TEST(test_03, case_7)
{
    auto s{""};
    auto solution{leetcode_03::Solution{}};
    auto result{solution.lengthOfLongestSubstring(s)};
    EXPECT_EQ(result, 1);
}