#include "leetcode_src/0200/289.h"
#include <gtest/gtest.h>

TEST(Test289, NormalCase)
{
    auto solution{leetcode_289::Solution()};
    auto input{std::vector<std::vector<int>>{{0, 1, 0},
                                             {0, 0, 1},
                                             {1, 1, 1},
                                             {0, 0, 0}}};
    solution.gameOfLife(input);
    auto expect{std::vector<std::vector<int>>{{0, 0, 0},
                                              {1, 0, 1},
                                              {0, 1, 1},
                                              {0, 1, 0}}};
    EXPECT_EQ(input, expect);
}