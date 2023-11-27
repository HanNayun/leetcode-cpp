#include "leetcode_src/2500/2520.h"

#include "gtest/gtest.h"

TEST(test_2520, case_0)
{
    auto actual{ Leetcode_2520::Solution{}.countDigits(7) };
    EXPECT_EQ(actual, 1);
}

TEST(test_2520, case_1)
{
    auto actual{ Leetcode_2520::Solution{}.countDigits(121) };
    EXPECT_EQ(actual, 2);
}

TEST(test_2520, case_2)
{
    auto actual{ Leetcode_2520::Solution{}.countDigits(1248) };
    EXPECT_EQ(actual, 4);
}
