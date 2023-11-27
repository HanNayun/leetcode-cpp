#include "leetcode_src/0000/04.h"
#include <gtest/gtest.h>

TEST(Test04, NormalOddCase)
{
    auto nums1{std::vector<int>{1, 3}};
    auto nums2{std::vector<int>{2}};
    auto solution{leetcode_04::Solution{}};
    auto result{solution.findMedianSortedArrays(nums1, nums2)};
    EXPECT_EQ(result, 2.0);
}

TEST(Test04, NormalEvenCase)
{
    auto nums1{std::vector<int>{1, 3}};
    auto nums2{std::vector<int>{2, 5}};
    auto solution{leetcode_04::Solution{}};
    auto result{solution.findMedianSortedArrays(nums1, nums2)};
    EXPECT_EQ(result, 2.5);
}

TEST(Test04, OneEmptyEvenCase)
{
    auto nums1{std::vector<int>{}};
    auto nums2{std::vector<int>{2, 5}};
    auto solution{leetcode_04::Solution{}};
    auto result{solution.findMedianSortedArrays(nums1, nums2)};
    EXPECT_EQ(result, 3.5);
}

TEST(Test04, OneEmptyOddCase)
{
    auto nums1{std::vector<int>{}};
    auto nums2{std::vector<int>{2, 5, 7}};
    auto solution{leetcode_04::Solution{}};
    auto result{solution.findMedianSortedArrays(nums1, nums2)};
    EXPECT_EQ(result, 5);
}

TEST(Test04, OneEmptyOddCase1)
{
    auto nums1{std::vector<int>{1}};
    auto nums2{std::vector<int>{}};
    auto solution{leetcode_04::Solution{}};
    auto result{solution.findMedianSortedArrays(nums1, nums2)};
    EXPECT_EQ(result, 1);
}

TEST(Test04, BothEmptyCase)
{
    auto nums1{std::vector<int>{}};
    auto nums2{std::vector<int>{}};
    auto solution{leetcode_04::Solution{}};
    auto result{solution.findMedianSortedArrays(nums1, nums2)};
    EXPECT_EQ(result, 0);
}

TEST(Test04, InFirstArrayCase)
{
    auto nums1{std::vector<int>{7, 100}};
    auto nums2{std::vector<int>{1, 3, 9}};
    auto solution{leetcode_04::Solution{}};
    auto result{solution.findMedianSortedArrays(nums1, nums2)};
    EXPECT_EQ(result, 7);
}

