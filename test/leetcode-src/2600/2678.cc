#include "leetcode_src/2600/2678.h"

#include "gtest/gtest.h"

TEST(test_2678, case_0)
{
    auto input{ std::vector<std::string>{ "7868190130M7522", "5303914400F9211", "9273338290F4010" }};
    auto actual{ Leetcode_2678::Solution{}.countSeniors(input) };
    auto expected{ 2 };
    EXPECT_EQ(actual, expected);
}

TEST(test_2678, case_1)
{
    auto input{ std::vector<std::string>{ "1313579440F2036", "2921522980M5644" }};
    auto actual{ Leetcode_2678::Solution{}.countSeniors(input) };
    auto expected{ 0 };
    EXPECT_EQ(actual, expected);
}

TEST(test_2678, case_2)
{
    auto input{ std::vector<std::string>{
            "9751302862F0693", "3888560693F7262", "5485983835F0649", "2580974299F6042",
            "9976672161M6561", "0234451011F8013", "4294552179O6482" }};
    auto actual{ Leetcode_2678::Solution{}.countSeniors(input) };
    auto expected{ 4 };
    EXPECT_EQ(actual, expected);
}