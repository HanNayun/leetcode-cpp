#include "leetcode_src/1400/1423.h"

#include <gtest/gtest.h>

TEST(Test1423, NormalCase)
{
    auto solution{ leetcode_1423::Solution{} };
    auto input{ std::vector<int>{ 1, 2, 3, 4, 5, 6, 1 } };
    auto output{ solution.maxScore(input, 3) };
    EXPECT_EQ(output, 12);

    input = { 2, 2, 2 };
    output = solution.maxScore(input, 2);
    EXPECT_EQ(output, 4);

    input = { 9, 7, 7, 9, 7, 7, 9 };
    output = solution.maxScore(input, 7);
    EXPECT_EQ(output, 55);
}
