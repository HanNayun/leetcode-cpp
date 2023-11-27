#include "leetcode_src/0000/13.h"

#include <gtest/gtest.h>

TEST(Test13, NormalCase)
{
    auto solution{leetcode_13::Solution()};

    auto s{"III"};
    EXPECT_EQ(solution.romanToInt(s), 3);

    s = "IV";
    EXPECT_EQ(solution.romanToInt(s), 4);

    s = "LVIII";
    EXPECT_EQ(solution.romanToInt(s), 58);

    s = "MCMXCIV";
    EXPECT_EQ(solution.romanToInt(s), 1994);
}