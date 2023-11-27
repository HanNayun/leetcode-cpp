#include "leetcode_src/0000/12.h"

#include <gtest/gtest.h>

TEST(Test12, NormalCase)
{
    auto solution{leetcode_12::Solution()};

    ASSERT_EQ(solution.intToRoman(3), "III");
    ASSERT_EQ(solution.intToRoman(4), "IV");
    ASSERT_EQ(solution.intToRoman(9), "IX");
    ASSERT_EQ(solution.intToRoman(58), "LVIII");
    ASSERT_EQ(solution.intToRoman(1994), "MCMXCIV");
}