#include "leetcode_src/1400/1402.h"

#include "gtest/gtest.h"

TEST(test_1402, case_0)
{
    auto input{ std::vector<int>{ -1, -8, 0, 5, -7 }};
    auto expected{ 14 };
    auto actual = Leetcode_1402::Solution{}.maxSatisfaction(input);
    EXPECT_EQ(expected, actual);
}

TEST(test_1402, case_1)
{
    auto input{ std::vector<int>{ 4, 3, 2 }};
    auto expected{ 20 };
    auto actual = Leetcode_1402::Solution{}.maxSatisfaction(input);
    EXPECT_EQ(expected, actual);
}

TEST(test_1402, case_2)
{
    auto input{ std::vector<int>{ -1, -4, -5 }};
    auto expected{ 0 };
    auto actual = Leetcode_1402::Solution{}.maxSatisfaction(input);
    EXPECT_EQ(expected, actual);
}