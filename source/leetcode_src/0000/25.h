#pragma once

#include <pthread.h>

#include "list_node.h"

namespace leetcode_25 {
class Solution
{
public:
    static ListNode* ReverseList(ListNode* start, ListNode* end)
    {
        if (!start || !end)
            return start;

        auto p1{start};
        auto p2{p1->next};
        start->next = end->next;
        while (p2)
        {
            const auto next = p2->next;
            p2->next = p1;
            if (p2 == end)break;
            p1 = p2;
            p2 = next;
        }

        return end;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k <= 1)
            return head;

        auto dummy{ListNode{}};
        dummy.next = head;
        auto prev = &dummy;

        auto start = head;
        auto end = head;
        while (start)
        {
            for (int i = 1; i < k; ++i)
            {
                if (end->next)
                    end = end->next;
                else
                    goto End;
            }

            prev->next = ReverseList(start, end);
            prev = start;
            start = start->next;
            end = start;
        }

    End:
        const auto res = dummy.next;
        dummy.next = nullptr;
        return res;
    }
};
}
