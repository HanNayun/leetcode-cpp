#include "leetcode_src/0300/318.h"

#include <gtest/gtest.h>

TEST(Test318, NormalCase)
{
    auto solution{ leetcode_318::Solution() };

    auto words{ std::vector<std::string>{ "abcw", "baz", "foo", "bar", "xtfn", "abcdef" }};
    EXPECT_EQ(solution.maxProduct(words), 16);

    words = { "a", "ab", "abc", "d", "cd", "bcd", "abcd" };
    EXPECT_EQ(solution.maxProduct(words), 4);

    words = { "a", "aa", "aaa", "aaaa" };
    EXPECT_EQ(solution.maxProduct(words), 0);
}