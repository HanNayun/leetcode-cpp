#include "leetcode_src/lcp/50.h"

#include "gtest/gtest.h"

TEST(test_lcp_50, case_0)
{
    auto gem = std::vector<int>{ 3, 1, 2 };
    auto operations = std::vector<std::vector<int>>{{ 0, 2 },
                                                    { 2, 1 },
                                                    { 2, 0 }};
    auto expected{ 2 };
    auto actual = Leetcode_Lcp_50::Solution{}.giveGem(gem, operations);
    EXPECT_EQ(expected, actual);
}

TEST(test_lcp_50, case_1)
{
    auto gem = std::vector<int>{ 100, 0, 50, 100 };
    auto operations = std::vector<std::vector<int>>{{ 0, 2 },
                                                    { 0, 1 },
                                                    { 3, 0 },
                                                    { 3, 0 }};
    auto expected{ 75 };
    auto actual = Leetcode_Lcp_50::Solution{}.giveGem(gem, operations);
    EXPECT_EQ(expected, actual);
}

TEST(test_lcp_50, case_2)
{
    auto gem = std::vector<int>{ 0, 0, 0, 0 };
    auto operations = std::vector<std::vector<int>>{{ 1, 2 },
                                                    { 3, 1 },
                                                    { 1, 2 }};
    auto expected{ 0 };
    auto actual = Leetcode_Lcp_50::Solution{}.giveGem(gem, operations);
    EXPECT_EQ(expected, actual);
}