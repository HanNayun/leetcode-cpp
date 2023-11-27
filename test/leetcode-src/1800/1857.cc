#include "gtest/gtest.h"
#include "leetcode_src/1800/1857.h"

TEST(Test_1857, Case_0)
{
    auto solution = leetcode_1857::Solution();
    auto colors = "abaca";
    auto edges = std::vector<std::vector<int>>{{0, 1},
                                               {0, 2},
                                               {2, 3},
                                               {3, 4}};
    auto expected = 3;
    auto result = solution.largestPathValue(colors, edges);
    EXPECT_EQ(result, expected);
}

TEST(Test_1857, Case_1)
{
    auto solution = leetcode_1857::Solution();
    auto colors = "a";
    auto edges = std::vector<std::vector<int>>{{0, 0}};
    auto expected = -1;
    auto result = solution.largestPathValue(colors, edges);
    EXPECT_EQ(result, expected);
}

TEST(Test_1857, Case_2)
{
    auto solution = leetcode_1857::Solution();
    auto colors = "ab";
    auto edges = std::vector<std::vector<int>>{{0, 1},
                                               {1, 1}};
    auto expected = -1;
    auto result = solution.largestPathValue(colors, edges);
    EXPECT_EQ(result, expected);
}