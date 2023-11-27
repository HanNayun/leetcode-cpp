#include "include/algorithm/Search.h"

#include "gtest/gtest.h"

TEST(test_binary_search, case_0)
{
    auto input{ std::vector<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 12 }};
    EXPECT_EQ(*leetcode_algorithm::Search::BinarySearch(input, 5), 5);
    EXPECT_EQ(*leetcode_algorithm::Search::BinarySearch(input, 0), *input.end());
    EXPECT_EQ(*leetcode_algorithm::Search::BinarySearch(input, 11), *input.end());
}