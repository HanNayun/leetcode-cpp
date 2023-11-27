#ifndef LEETCODE_CC_24_H
#define LEETCODE_CC_24_H

#include "include/list_node.h"

namespace Leetcode_24
{
    class Solution
    {
    public:
        ListNode* swapPairs(ListNode* head)
        {
            if (head == nullptr)
            {
                return head;
            }

            auto dummy = new ListNode;
            auto res = dummy;
            auto p1 = head;
            auto p2 = head->next;

            dummy->next = p1;
            while (p2 != nullptr)
            {
                p1->next = p2->next;
                p2->next = p1;
                dummy->next = p2;
                dummy = dummy->next->next;
                p1 = p1->next;
                p2 = p1 == nullptr ? nullptr : p1->next;
            }

            auto ans = res->next;
            delete res;
            return ans;
        }
    };
}

#endif //LEETCODE_CC_24_H
