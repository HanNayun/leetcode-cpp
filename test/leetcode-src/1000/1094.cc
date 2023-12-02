#include "leetcode_src/1000/1094.h"

#include <gtest/gtest.h>

TEST(Test1094, NormalCase)
{
    auto solution{ leetcode_1094::Solution{} };
    auto trips = std::vector<std::vector<int>>{
        { 2, 1, 5 },
        { 3, 3, 7 }
    };
    EXPECT_FALSE(solution.carPooling(trips, 4));
    EXPECT_TRUE(solution.carPooling(trips, 5));
}
