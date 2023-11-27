#include "leetcode_src/1100/1155.h"

#include "gtest/gtest.h"

TEST(test_1155, case_0)
{
    auto actual{ Leetcode_1155::Solution{}.numRollsToTarget(1, 6, 3) };
    EXPECT_EQ(1, actual);
}

TEST(test_1155, case_1)
{
    auto actual{ Leetcode_1155::Solution{}.numRollsToTarget(2, 6, 7) };
    EXPECT_EQ(6, actual);
}

TEST(test_1155, case_2)
{
    auto actual{ Leetcode_1155::Solution{}.numRollsToTarget(30, 30, 500) };
    EXPECT_EQ(222616187, actual);
}