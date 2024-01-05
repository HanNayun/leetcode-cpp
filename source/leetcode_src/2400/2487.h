#pragma once

#include "list_node.h"

#include <stack>

namespace leetcode_2487 {
class Solution
{
public:
    ListNode* removeNodes(ListNode* head)
    {
        std::stack<ListNode*> stack;
        auto now{head};
        while (now)
        {
            while (!stack.empty() && stack.top()->val < now->val)
            {
                auto top{stack.top()};
                stack.pop();
                top->next = nullptr;
                delete top;
            }

            stack.push(now);
            now = now->next;
        }

        ListNode* res{nullptr};
        while (!stack.empty())
        {
            auto top{stack.top()};
            stack.pop();
            top->next = res;
            res = top;
        }

        return res;
    }
};

}