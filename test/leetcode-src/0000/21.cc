#include "leetcode_src/0000/21.h"

#include <gtest/gtest.h>

TEST(Test21, NormalCase)
{
    auto list1 = ListNode::CreateList({ 1, 2, 4 });
    auto list2 = ListNode::CreateList({ 1, 3, 4 });
    auto res = Leetcode_21::Solution{}.mergeTwoLists(list1, list2);
    auto expect = std::vector<int>{ 1, 1, 2, 3, 4, 4 };
    EXPECT_EQ(ListNode::ListToVector(res), expect);
    delete res;

    list1 = ListNode::CreateList({});
    list2 = ListNode::CreateList({});
    res = Leetcode_21::Solution{}.mergeTwoLists(list1, list2);
    expect = {};
    EXPECT_EQ(ListNode::ListToVector(res), expect);
    delete res;

    list1 = ListNode::CreateList({});
    list2 = ListNode::CreateList({ 0 });
    res = Leetcode_21::Solution{}.mergeTwoLists(list1, list2);
    expect = { 0 };
    EXPECT_EQ(ListNode::ListToVector(res), expect);
    delete res;
}
