#include "leetcode_src/0000/25.h"

#include<gtest/gtest.h>

TEST(Test25, NormalCase)
{
    auto head = ListNode::CreateList({ 1, 2, 3, 4, 5 });
    auto res = leetcode_25::Solution{}.reverseKGroup(head, 2);
    auto ans = std::vector<int>{ 2, 1, 4, 3, 5 };
    EXPECT_EQ(ListNode::ListToVector(res), ans);
    delete res;

    head = ListNode::CreateList({ 1, 2, 3, 4, 5 });
    res = leetcode_25::Solution{}.reverseKGroup(head, 3);
    ans = std::vector<int>{ 3, 2, 1, 4, 5 };
    EXPECT_EQ(ListNode::ListToVector(res), ans);
    delete res;
}
