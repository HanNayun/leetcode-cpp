#include "leetcode_src/0000/09.h"

#include <gtest/gtest.h>

TEST(Test09, NormalCase)
{
    auto solution{leetcode_09::Solution()};

    EXPECT_TRUE(solution.isPalindrome(121));
    EXPECT_TRUE(solution.isPalindrome(1));
    EXPECT_FALSE(solution.isPalindrome(10));
}

TEST(Test09, NegativeCase)
{
    auto solution{leetcode_09::Solution()};

    EXPECT_FALSE(solution.isPalindrome(-121));
    EXPECT_FALSE(solution.isPalindrome(-1));
}

TEST(Test09, ZeroCase)
{
    auto solution{leetcode_09::Solution()};

    EXPECT_TRUE(solution.isPalindrome(0));
}

TEST(Test09, OverflowCase)
{
    auto solution{leetcode_09::Solution()};

    EXPECT_FALSE(solution.isPalindrome(1234567899));
}