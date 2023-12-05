#include "leetcode_src/0000/27.h"
#include "utils/vector-utils.h"
#include <gtest/gtest.h>
#include <__algorithm/ranges_sort.h>

TEST(Test27, NormalCase)
{
    auto solution{ leetcode_27::Solution{} };
    auto input{ std::vector<int>{ 3, 2, 2, 3 } };
    auto val{ 3 };
    auto output{ 2 };
    EXPECT_EQ(solution.removeElement(input, val), output);
    std::ranges::sort(input.begin(), input.begin() + output);
    utils::VectorUtils::TestFristKthElemnetSame(input, { 2, 2 }, output);

    input = { 0, 1, 2, 2, 3, 0, 4, 2 };
    val = 2;
    output = 5;
    EXPECT_EQ(solution.removeElement(input, val), output);
    std::ranges::sort(input.begin(), input.begin() + output);
    utils::VectorUtils::TestFristKthElemnetSame(input, { 0, 0, 1, 3, 4 }, output);

    input = {};
    val = 0;
    output = 0;
    EXPECT_EQ(solution.removeElement(input, val), output);
    utils::VectorUtils::TestFristKthElemnetSame(input, {}, output);
    std::ranges::sort(input.begin(), input.begin() + output);
    utils::VectorUtils::TestFristKthElemnetSame(input, {}, output);

    input = { 2 };
    val = 3;
    output = 1;
    EXPECT_EQ(solution.removeElement(input, val), output);
    std::ranges::sort(input.begin(), input.begin() + output);
    utils::VectorUtils::TestFristKthElemnetSame(input, { 2 }, output);
}
