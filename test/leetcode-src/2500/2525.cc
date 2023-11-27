#include "leetcode_src/2500/2525.h"

#include "gtest/gtest.h"

TEST(test_2525, case_0)
{
    auto solution{ Leetcode_2525::Solution{}};
    auto expected{ std::string{ "Heavy" }};
    auto result{ solution.categorizeBox(1000, 35, 700, 300) };
    EXPECT_EQ(result, expected);
}

TEST(test_2525, case_1)
{
    auto solution{ Leetcode_2525::Solution{}};
    auto expected{ std::string{ "Neither" }};
    auto result{ solution.categorizeBox(200, 50, 800, 50) };
    EXPECT_EQ(result, expected);
}

TEST(test_2525, case_2)
{
    auto solution{ Leetcode_2525::Solution{}};
    auto expected{ std::string{ "Bulky" }};
    auto result{ solution.categorizeBox(10000, 1, 1, 1) };
    EXPECT_EQ(result, expected);
}

TEST(test_2525, case_3)
{
    auto solution{ Leetcode_2525::Solution{}};
    auto expected{ std::string{ "Both" }};
    auto result{ solution.categorizeBox(1000, 1000, 1000, 1000) };
    EXPECT_EQ(result, expected);
}