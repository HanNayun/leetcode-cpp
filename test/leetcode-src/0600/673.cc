#include "leetcode_src/0600/673.h"

#include "gtest/gtest.h"

TEST(Test_673, Case_0)
{
    Leetcode_673::Solution solution{};
    std::vector<int> nums{ 1, 3, 5, 4, 7 };
    int expected{ 2 };
    EXPECT_EQ(solution.findNumberOfLIS(nums), expected);
}

TEST(Test_673, Case_1)
{
    Leetcode_673::Solution solution{};
    std::vector<int> nums{ 2, 2, 2, 2, 2 };
    int expected{ 5 };
    EXPECT_EQ(solution.findNumberOfLIS(nums), expected);
}