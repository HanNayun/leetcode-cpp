#include "leetcode_src/0000/17.h"
#include <gtest/gtest.h>

TEST(Test17, NormalCase)
{
    auto solution{ leetcode_17::Solution{}};

    auto digits{ std::string{ "23" }};
    auto expected{ std::vector<std::string>{ "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }};
    EXPECT_EQ(solution.letterCombinations(digits), expected);

    digits = std::string{ "" };
    expected = std::vector<std::string>{};
    EXPECT_EQ(solution.letterCombinations(digits), expected);

    digits = std::string{ "2" };
    expected = std::vector<std::string>{ "a", "b", "c" };
    EXPECT_EQ(solution.letterCombinations(digits), expected);
}