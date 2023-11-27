#include "leetcode_src/0800/828.h"
#include <gtest/gtest.h>

TEST(Test828, NormalCase)
{
    auto solution{leetcode_828::Solution()};
    auto input{std::string{"ABC"}};
    EXPECT_EQ(solution.uniqueLetterString(input), 10);

    input = "ABA";
    EXPECT_EQ(solution.uniqueLetterString(input), 8);

    input = "LEETCODE";
    EXPECT_EQ(solution.uniqueLetterString(input), 92);
}