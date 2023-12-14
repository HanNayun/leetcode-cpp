#pragma once

#include "list_node.h"

namespace leetcode_19 {
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (head == nullptr)
            return head;

        auto* p = head;
        auto* p2 = head;
        auto len = 1;

        while (p2->next != nullptr)
        {
            p2 = p2->next;
            ++len;
        }

        if (len == 1)
            return nullptr;
        if (len == n)
        {
            auto res = head->next;
            head->next = nullptr;
            delete head;
            return res;
        }

        len -= n + 1;
        while (len > 0)
        {
            p = p->next;
            --len;
        }

        auto new_next = p->next->next;
        auto next = p->next;
        p->next = new_next;
        next->next = nullptr;
        delete next;

        return head;
    }
};
}
