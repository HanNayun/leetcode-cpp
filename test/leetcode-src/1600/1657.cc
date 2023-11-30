#include "leetcode_src/1600/1657.h"

#include <gtest/gtest.h>

TEST(Test1657, NormalCase)
{
    auto solution{ leetcode_1657::Solution{} };
    EXPECT_TRUE(solution.closeStrings("abc", "bca"));
    EXPECT_FALSE(solution.closeStrings("a", "aa"));
    EXPECT_TRUE(solution.closeStrings("cabbba", "abbccc"));
}
