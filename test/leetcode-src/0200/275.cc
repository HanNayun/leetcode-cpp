#include "leetcode_src/0200/275.h"
#include "gtest/gtest.h"

TEST(Test275, Case0)
{
    auto citations{ std::vector<int>{ 0, 1, 3, 5, 6 }};
    auto solution{ Leetcode_275::Solution() };
    auto result{ solution.hIndex(citations) };
    EXPECT_EQ(result, 3);
}

TEST(Test275, Case1)
{
    auto citations{ std::vector<int>{ 1, 2, 100 }};
    auto solution{ Leetcode_275::Solution() };
    auto result{ solution.hIndex(citations) };
    EXPECT_EQ(result, 2);
}

TEST(Test275, Case2)
{
    auto citations{ std::vector<int>{ 3, 3 }};
    auto solution{ Leetcode_275::Solution() };
    auto result{ solution.hIndex(citations) };
    EXPECT_EQ(result, 2);
}

TEST(Test275, Case3)
{
    auto citations{ std::vector<int>{ 0, 0, 4, 4 }};
    auto solution{ Leetcode_275::Solution() };
    auto result{ solution.hIndex(citations) };
    EXPECT_EQ(result, 2);
}

TEST(Test275, EmptyInput)
{
    auto citations{ std::vector<int>{}};
    auto solution{ Leetcode_275::Solution() };
    auto result{ solution.hIndex(citations) };
    EXPECT_EQ(result, 0);
}

TEST(Test275, Case4)
{
    auto citations{ std::vector<int>{ 1, 3, 3, 3 }};
    auto solution{ Leetcode_275::Solution() };
    auto result{ solution.hIndex(citations) };
    EXPECT_EQ(result, 3);
}