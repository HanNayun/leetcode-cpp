#include "list_node.h"

ListNode* CreateList(const std::vector<int>& values)
{
    auto dummy{new ListNode};
    auto res{dummy};

    for (auto& v: values)
    {
        res->next = new ListNode;
        res = res->next;
        res->val = v;
    }

    return dummy->next;
}

std::vector<int> ListToVector(ListNode* list)
{
    auto res{std::vector<int>{}};
    while (list != nullptr)
    {
        res.push_back(list->val);
        list = list->next;
    }

    return res;
}