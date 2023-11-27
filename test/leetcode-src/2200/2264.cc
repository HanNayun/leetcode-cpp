#include "leetcode_src/2200/2264.h"

#include "gtest/gtest.h"

TEST(Test_2264, Case_0)
{
    auto solution = Leetcode_2264::Solution();
    auto num = std::string{ "6777133339" };
    auto result = solution.largestGoodInteger(num);
    EXPECT_EQ(result, "777");
}

TEST(Test_2264, Case_1)
{
    auto solution = Leetcode_2264::Solution();
    auto num = std::string{ "2300019" };
    auto result = solution.largestGoodInteger(num);
    EXPECT_EQ(result, "000");
}

TEST(Test_2264, Case_2)
{
    auto solution = Leetcode_2264::Solution();
    auto num = std::string{ "42352338" };
    auto result = solution.largestGoodInteger(num);
    EXPECT_EQ(result, "");
}

