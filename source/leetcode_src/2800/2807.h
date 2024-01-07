#pragma once

#include "list_node.h"

namespace leetcode_2807 {
class Solution
{
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {

        auto node{head};

        while (node->next)
        {
            auto gcd{GetGcd(node->val, node->next->val)};
            auto next{new ListNode(gcd, node->next)};
            node->next = next;
            node = next->next;
        }
        return head;
    }

    int GetGcd(int a, int b)
    {
        if (a < b)
            std::swap(a, b);

        while (b != 0)
        {
            auto tmp{a % b};
            a = b;
            b = tmp;
        }

        return a;
    }
};
}
