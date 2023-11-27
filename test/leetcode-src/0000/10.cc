#include "leetcode_src/0000/10.h"

#include <gtest/gtest.h>

TEST(Test10, NormalCase)
{
    leetcode_10::Solution solution;
    auto src{"aa"};
    auto pattern{"a"};

    auto res{solution.isMatch(src, pattern)};
    EXPECT_EQ(res, false);

    src = "aaaa";
    pattern = "aaaa";
    res = solution.isMatch(src, pattern);
    EXPECT_EQ(res, true);
}

TEST(Test10, WildCharCase)
{
    leetcode_10::Solution solution;
    auto src{"aa"};
    auto pattern{"a*"};

    auto res{solution.isMatch(src, pattern)};
    EXPECT_EQ(res, true);
}