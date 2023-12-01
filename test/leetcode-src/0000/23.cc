#include "leetcode_src/0000/23.h"

#include<gtest/gtest.h>

TEST(Test23, NormalCase)
{
    auto solution{ leetcode_23::Solution{} };
    auto lists = std::vector<ListNode*>{
        ListNode::CreateList({ 1, 4, 5 }),
        ListNode::CreateList({ 1, 3, 4 }),
        ListNode::CreateList({ 2, 6 })
    };

    auto res = solution.mergeKLists(lists);
    auto ans = std::vector<int>{ 1, 1, 2, 3, 4, 4, 5, 6 };
    EXPECT_EQ(ListNode::ListToVector(res), ans);
    delete res;
};
