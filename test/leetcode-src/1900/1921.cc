#include "gtest/gtest.h"
#include "leetcode_src/1900/1921.h"

TEST(Test_1921, Case_0)
{
    auto solution = Leetcode_1921::Solution();
    auto dist = std::vector<int>{ 1, 3, 4 };;
    auto speed = std::vector<int>{ 1, 1, 1 };
    auto result = solution.eliminateMaximum(dist, speed);
    EXPECT_EQ(result, 3);
}

TEST(Test_1921, Case_1)
{
    auto solution = Leetcode_1921::Solution();
    auto dist = std::vector<int>{ 1, 1, 2, 3 };;
    auto speed = std::vector<int>{ 1, 1, 1, 1 };
    auto result = solution.eliminateMaximum(dist, speed);
    EXPECT_EQ(result, 1);
}

TEST(Test_1921, Case_2)
{
    auto solution = Leetcode_1921::Solution();
    auto dist = std::vector<int>{ 3, 2, 4 };;
    auto speed = std::vector<int>{ 5, 3, 2 };
    auto result = solution.eliminateMaximum(dist, speed);
    EXPECT_EQ(result, 1);
}