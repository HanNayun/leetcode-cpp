#include "leetcode_src/2300/2300.h"
#include <gtest/gtest.h>

TEST(Test2300, NormalCase)
{
    auto solution{ leetcode_2300::Solution{}};

    auto spells{ std::vector<int>{ 5, 1, 3 }};
    auto potions{ std::vector<int>{ 1, 2, 3, 4, 5 }};
    auto success{ 7 };
    auto expected{ std::vector<int>{ 4, 0, 3 }};
    EXPECT_EQ(solution.successfulPairs(spells, potions, success), expected);

    spells = std::vector<int>{ 3, 1, 2 };
    potions = std::vector<int>{ 8, 5, 8 };
    success = 16;
    expected = std::vector<int>{ 2, 0, 2 };
    EXPECT_EQ(solution.successfulPairs(spells, potions, success), expected);
}