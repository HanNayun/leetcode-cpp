#include "leetcode_src/2100/2103.h"

#include "gtest/gtest.h"

TEST(Test2103, NormalCase)
{
    auto solution{ leetcode_2103::Solution() };

    EXPECT_EQ(solution.countPoints("B0B6G0R6R0R6G9"), 1);
    EXPECT_EQ(solution.countPoints("B0R0G0R9R0B0G0"), 1);
    EXPECT_EQ(solution.countPoints("G4"), 0);
}