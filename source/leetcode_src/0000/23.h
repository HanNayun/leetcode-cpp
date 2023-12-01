#pragma once
#include "include/list_node.h"

#include<queue>

namespace leetcode_23{
class Solution
{
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        return MergeLists(lists, 0, lists.size() - 1);
    }

    ListNode* MergeLists(std::vector<ListNode*>& lists, int l, int r)
    {
        if (l == r)
            return lists[l];

        if (l > r)
            return nullptr;

        const int mid = (l + r) / 2;
        return MergeTwoList(MergeLists(lists, l, mid), MergeLists(lists, mid + 1, r));
    }

    static ListNode* MergeTwoList(ListNode* list1, ListNode* list2)
    {
        if ((!list1) || (!list2))
            return list1 == nullptr ? list2 : list1;

        auto dummy = new ListNode;
        auto res = dummy;
        ListNode* next = nullptr;
        while (list1 && list2)
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
        dummy = res;
        res = res->next;
        dummy->next = nullptr;
        delete dummy;

        return res;
    }
};
}
