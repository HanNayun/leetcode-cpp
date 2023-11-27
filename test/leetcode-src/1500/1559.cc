#include "leetcode_src/1500/1559.h"

#include "gtest/gtest.h"

TEST(test_1559, case_0)
{
    auto grid{ std::vector<std::vector<char>>{
            { 'a', 'a', 'a', 'a' },
            { 'a', 'b', 'b', 'a' },
            { 'a', 'b', 'b', 'a' },
            { 'a', 'a', 'a', 'a' }}};

    auto actual{ Leetcode_1559::Solution{}.containsCycle(grid) };
    auto expected{ true };
    EXPECT_EQ(actual, expected);
}

TEST(test_1559, case_1)
{
    auto grid{ std::vector<std::vector<char>>{
            { 'c', 'c', 'c', 'a' },
            { 'c', 'd', 'c', 'c' },
            { 'c', 'c', 'e', 'c' },
            { 'f', 'c', 'c', 'c' }}};

    auto actual{ Leetcode_1559::Solution{}.containsCycle(grid) };
    auto expected{ true };
    EXPECT_EQ(actual, expected);
}

TEST(test_1559, case_2)
{
    auto grid{ std::vector<std::vector<char>>{
            { 'a', 'b', 'b' },
            { 'b', 'z', 'b' },
            { 'b', 'b', 'a' }}};

    auto actual{ Leetcode_1559::Solution{}.containsCycle(grid) };
    auto expected{ false };
    EXPECT_EQ(actual, expected);
}

