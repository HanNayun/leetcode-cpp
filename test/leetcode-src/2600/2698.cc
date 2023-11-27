#include "leetcode_src/2600/2698.h"

#include "gtest/gtest.h"

TEST(test_2698, case_0)
{
    auto actual{ Leetcode_2698::Solution{}.punishmentNumber(37) };
    EXPECT_EQ(actual, 1478);
}

TEST(test_2698, case_1)
{
    auto actual{ Leetcode_2698::Solution{}.punishmentNumber(10) };
    EXPECT_EQ(actual, 182);
}

TEST(test_2698, case_2)
{
    auto actual{ Leetcode_2698::Solution{}.punishmentNumber(1000) };
    EXPECT_EQ(actual, 10804657);
}

TEST(test_2698, case_3)
{
    auto actual{ Leetcode_2698::Solution{}.punishmentNumber(414) };
    EXPECT_EQ(actual, 772866);
}
