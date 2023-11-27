#include "leetcode_src/0200/274.h"

#include "gtest/gtest.h"

TEST(Test274, NormalCase0)
{
    Leetcode_274::Solution solution{};
    std::vector<int> input{ 3, 0, 6, 1, 5 };
    auto result{ solution.hIndex(input) };
    EXPECT_EQ(result, 3);
}

TEST(Test274, NormalCase1)
{
    Leetcode_274::Solution solution{};
    std::vector<int> input{ 1, 3, 1 };
    auto result{ solution.hIndex(input) };
    EXPECT_EQ(result, 1);
}

TEST(Test274, NormalCase2)
{
    Leetcode_274::Solution solution{};
    std::vector<int> input{ 100 };
    auto result{ solution.hIndex(input) };
    EXPECT_EQ(result, 1);
}

TEST(Test274, NormalCase3)
{
    Leetcode_274::Solution solution{};
    std::vector<int> input{ 3, 3 };
    auto result{ solution.hIndex(input) };
    EXPECT_EQ(result, 2);
}

TEST(Test274, ZeroCase)
{
    Leetcode_274::Solution solution{};
    std::vector<int> input{ 0 };
    auto result{ solution.hIndex(input) };
    EXPECT_EQ(result, 0);
}

TEST(Test274, EmptyCase)
{
    Leetcode_274::Solution solution{};
    std::vector<int> input{};
    auto result{ solution.hIndex(input) };
    EXPECT_EQ(result, 0);
}