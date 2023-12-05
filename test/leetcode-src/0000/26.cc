#include "leetcode_src/0000/26.h"
#include "utils/vector-utils.h"

#include <gtest/gtest.h>
#include <numeric>

TEST(Test26, NomralCase)
{
    auto solution{ leetcode_26::Solution{} };
    auto input{ std::vector<int>{ 1, 1, 2 } };
    auto output{ solution.removeDuplicates(input) };
    EXPECT_EQ(output, 2);
    utils::VectorUtils::TestFristKthElemnetSame(input, { 1, 2 }, output);
}

