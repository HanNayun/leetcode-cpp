#pragma once

#include "include/list_node.h"

namespace leetcode_02
{
    class Solution
    {
    public:
        ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2)
        {
            auto dummy{new ListNode};
            auto res{dummy};

            auto carry{0};
            while (l1 != nullptr && l2 != nullptr)
            {
                res->next = new ListNode;
                res = res->next;

                const auto sum{carry + l1->val + l2->val};
                carry = sum / 10;
                res->val = sum % 10;
                l1 = l1->next;
                l2 = l2->next;
            }

            while (l1 != nullptr)
            {
                res->next = new ListNode;
                res = res->next;

                auto sum{carry + l1->val};
                carry = sum / 10;
                res->val = sum % 10;
                l1 = l1->next;
            }

            while (l2 != nullptr)
            {
                res->next = new ListNode;
                res = res->next;

                auto sum{carry + l2->val};
                carry = sum / 10;
                res->val = sum % 10;
                l2 = l2->next;
            }

            if (carry)
            {
                res->next = new ListNode;
                res = res->next;
                res->val = carry;
            }

            return dummy->next;
        }
    };
}
