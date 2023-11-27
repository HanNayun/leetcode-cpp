#include "gtest/gtest.h"
#include "leetcode_src/0300/331.h"

TEST(Test_331, Expect_True)
{
    auto solution = leetcode_331::Solution();
    auto input = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    EXPECT_TRUE(solution.isValidSerialization(input));

    input = "9,#,93,#,9,9,#,#,#";
    EXPECT_TRUE(solution.isValidSerialization(input));
}

TEST(Test_331, Expect_False)
{
    auto solution = leetcode_331::Solution();
    auto input = "1,#";
    EXPECT_FALSE(solution.isValidSerialization(input));

    input = "9,#,#,1";
    EXPECT_FALSE(solution.isValidSerialization(input));

    input = "1";
    EXPECT_FALSE(solution.isValidSerialization(input));
}

