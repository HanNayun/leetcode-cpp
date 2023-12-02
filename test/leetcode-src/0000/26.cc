#include "leetcode_src/0000/26.h"

#include <gtest/gtest.h>
#include <numeric>

void TestVectorKthElemnetSame(const std::vector<int>& vec1,
                              const std::vector<int>& vec2,
                              int k)
{
    for (int i = 0; i < k; ++i)
        EXPECT_EQ(vec1[i], vec2[i]);
}

TEST(Test26, NomralCase)
{
    auto solution{ leetcode_26::Solution{} };
    auto input{ std::vector<int>{ 1, 1, 2 } };
    auto output{ solution.removeDuplicates(input) };
    EXPECT_EQ(output, 2);
    TestVectorKthElemnetSame(input, { 1, 2 }, output);
}

