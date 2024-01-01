#include "leetcode_src/1500//1599.h"

#include <gtest/gtest.h>

TEST(Test1599, NormalCase)
{
    std::vector<int> customers{8, 3};
    int boarding_cost{5};
    int running_cost{6};

    leetcode_1599::Solution solution;
    auto actual = solution.minOperationsMaxProfit(customers, boarding_cost, running_cost);
    EXPECT_EQ(3, actual);


    customers = {10, 10, 6, 4, 7};
    boarding_cost = 3;
    running_cost = 8;
    actual = solution.minOperationsMaxProfit(customers, boarding_cost, running_cost);
    EXPECT_EQ(9, actual);

    customers = {10, 10, 1, 0, 0};
    boarding_cost = 4;
    running_cost = 4;
    actual = solution.minOperationsMaxProfit(customers, boarding_cost, running_cost);
    EXPECT_EQ(5, actual);
}