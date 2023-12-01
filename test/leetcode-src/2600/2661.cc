#include "leetcode_src/2600/2661.h"

#include <gtest/gtest.h>

TEST(Test2661, NormalCase)
{
    auto solution{ leetcode_2661::Solution{} };
    auto arr{ std::vector<int>{ 1, 3, 4, 2 } };
    auto mat{ std::vector<std::vector<int>>{ { 1, 4 }, { 2, 3 } } };
    EXPECT_EQ(solution.firstCompleteIndex(arr, mat), 2);

    arr = { 2, 8, 7, 4, 1, 3, 5, 6, 9 };
    mat = { { 3, 2, 5 }, { 1, 4, 6 }, { 8, 7, 9 } };
    EXPECT_EQ(solution.firstCompleteIndex(arr, mat), 3);

    arr = { 1, 4, 5, 2, 6, 3 };
    mat = { { 4, 3, 5 }, { 1, 2, 6 } };
    EXPECT_EQ(solution.firstCompleteIndex(arr, mat), 1);
}
