#include "leetcode_src/2100/2127.h"

#include "gtest/gtest.h"

TEST(Test2127, NormalCase)
{
    auto solution{ leetcode_2127::Solution() };
    auto input{ std::vector<int>{ 2, 2, 1, 2 }};
    auto res{ solution.maximumInvitations(input) };
    EXPECT_EQ(res, 3);

    input = std::vector<int>{ 1, 2, 0 };
    res = solution.maximumInvitations(input);
    EXPECT_EQ(res, 3);

    input = std::vector<int>{ 3, 0, 1, 4, 1 };
    res = solution.maximumInvitations(input);
    EXPECT_EQ(res, 4);
}