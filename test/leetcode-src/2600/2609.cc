#include "leetcode_src/2600/2609.h"

#include <gtest/gtest.h>

TEST(Test2069, NormalCase)
{
    auto solution{ leetcode_2609::Solution() };

    auto s{ std::string{ "01000111" }};
    EXPECT_EQ(solution.findTheLongestBalancedSubstring(s), 6);

    s = "00111";
    EXPECT_EQ(solution.findTheLongestBalancedSubstring(s), 4);

    s = "1111";
    EXPECT_EQ(solution.findTheLongestBalancedSubstring(s), 0);

    s = "001";
    EXPECT_EQ(solution.findTheLongestBalancedSubstring(s), 2);
}