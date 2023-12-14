#include "leetcode_src/0000/02.h"

#include <gtest/gtest.h>

#include <vector>

TEST(test_02, case_0)
{
    auto list_1_value{std::vector<int>{9, 9, 9, 9, 9, 9, 9}};
    auto list_2_value{std::vector<int>{9, 9, 9, 9}};
    auto list_1{ListNode::CreateList(list_1_value)};
    auto list_2{ListNode::CreateList(list_2_value)};

    auto solution{leetcode_02::Solution{}};
    auto result{ListNode::ListToVector(solution.addTwoNumbers(list_1, list_2))};
    auto expected{std::vector<int>{8, 9, 9, 9, 0, 0, 0, 1}};
    EXPECT_EQ(result, expected);
}

TEST(test_02, case_1)
{
    auto list_1_value{std::vector<int>{0}};
    auto list_2_value{std::vector<int>{0}};
    auto list_1{ListNode::CreateList(list_1_value)};
    auto list_2{ListNode::CreateList(list_2_value)};

    auto solution{leetcode_02::Solution{}};
    auto result{ListNode::ListToVector(solution.addTwoNumbers(list_1, list_2))};
    auto expected{std::vector<int>{0}};
    EXPECT_EQ(result, expected);
}

TEST(test_02, case_2)
{
    auto list_1_value{std::vector<int>{2, 4, 3}};
    auto list_2_value{std::vector<int>{5, 6, 4}};
    auto list_1{ListNode::CreateList(list_1_value)};
    auto list_2{ListNode::CreateList(list_2_value)};

    auto solution{leetcode_02::Solution{}};
    auto result{ListNode::ListToVector(solution.addTwoNumbers(list_1, list_2))};
    auto expected{std::vector<int>{7, 0, 8}};
    EXPECT_EQ(result, expected);
}

TEST(test_02, case_3)
{
    auto list_1_value{std::vector<int>{2, 4, 3}};
    auto list_2_value{std::vector<int>{5, 6, 4, 1}};
    auto list_1{ListNode::CreateList(list_1_value)};
    auto list_2{ListNode::CreateList(list_2_value)};

    auto solution{leetcode_02::Solution{}};
    auto result{ListNode::ListToVector(solution.addTwoNumbers(list_1, list_2))};
    auto expected{std::vector<int>{7, 0, 8, 1}};
    EXPECT_EQ(result, expected);
}
