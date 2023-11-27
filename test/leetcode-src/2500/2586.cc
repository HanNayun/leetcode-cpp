#include "leetcode_src/2500/2586.h"

#include <gtest/gtest.h>

TEST(Test2586, NormalCase)
{
    auto solution{ leetcode_2586::Solution() };

    auto words{ std::vector<std::string>{ "are", "amy", "u" }};
    auto left{ 0 };
    auto right{ 2 };
    ASSERT_EQ(solution.vowelStrings(words, left, right), 2);

    words = { "hey", "aeo", "mu", "ooo", "artro" };
    left = 1;
    right = 4;
    ASSERT_EQ(solution.vowelStrings(words, left, right), 3);
}