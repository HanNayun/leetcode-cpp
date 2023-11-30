#include "leetcode_src/0000/22.h"

#include <gtest/gtest.h>

TEST(Test22, NormalCase)
{
    auto solution{ leetcode_22::Solution{} };
    auto res = solution.generateParenthesis(3);
    EXPECT_EQ(res.size(), 5);
    auto expected{ std::set<std::string>{ res.begin(), res.end() } };
    auto parentheses_set{ std::set<std::string>{ "((()))", "(()())", "(())()", "()(())", "()()()" } };
    EXPECT_EQ(expected, parentheses_set);
}
