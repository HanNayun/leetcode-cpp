#pragma once

#include "list_node.h"

namespace leetcode_24 {
class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head)
            return nullptr;

        auto p1 = head;
        auto p2 = p1->next;
        if (!p2)
            return p1;

        auto dummy = ListNode{};
        dummy.next = p2;
        auto prev = &dummy;

        while (p2 != nullptr)
        {
            p1->next = p2->next;
            p2->next = p1;
            prev->next = p2;

            prev = p1;
            p1 = p1->next;
            p2 = p1 ? p1->next : nullptr;
        }

        auto res = dummy.next;
        dummy.next = nullptr;
        return res;
    }
};
}

