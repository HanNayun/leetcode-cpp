#include "leetcode_src/0000/14.h"

#include <gtest/gtest.h>

TEST(Test14, NormalCase)
{
    auto solution{ leetcode_14::Solution() };

    auto strs{ std::vector<std::string>{ "flower", "flow", "flight" }};
    ASSERT_EQ(solution.longestCommonPrefix(strs), "fl");

    strs = { "dog", "racecar", "car" };
    ASSERT_EQ(solution.longestCommonPrefix(strs), "");
}