#include "leetcode_src/0100/187.h"

#include "gtest/gtest.h"

TEST(Test187, NormalCase)
{
    auto solution{ leetcode_187::Solution() };

    auto s{ std::string{ "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT" }};
    auto expect{ std::vector<std::string>{ "AAAAACCCCC", "CCCCCAAAAA" }};
    ASSERT_EQ(solution.findRepeatedDnaSequences(s), expect);

    s = "AAAAAAAAAAAAA";
    expect = { "AAAAAAAAAA" };
    ASSERT_EQ(solution.findRepeatedDnaSequences(s), expect);
}