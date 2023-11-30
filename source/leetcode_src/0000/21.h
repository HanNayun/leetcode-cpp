#pragma once

#include "include/list_node.h"

namespace Leetcode_21{
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        auto dummy = new ListNode;
        const auto res = dummy;
        ListNode* next = nullptr;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                next = list1;
                list1 = list1->next;
            }
            else
            {
                next = list2;
                list2 = list2->next;
            }

            dummy->next = next;
            dummy = dummy->next;
            dummy->next = nullptr;
        }

        dummy->next = list1 == nullptr ? list2 : list1;
        auto ans = res->next;
        res->next = nullptr;
        delete res;

        return ans;
    }
};
}
