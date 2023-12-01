#include "leetcode_src/0000/24.h"

#include<gtest/gtest.h>

TEST(Test24, NormalCase)
{
    auto solution{ leetcode_24::Solution{} };
    auto head = ListNode::CreateList({ 1, 2, 3, 4 });
    auto res = solution.swapPairs(head);
    auto ans = std::vector<int>{ 2, 1, 4, 3 };
    EXPECT_EQ(ListNode::ListToVector(res), ans);
}
