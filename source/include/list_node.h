#pragma once

#include <vector>

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr)
    {
    }

    explicit ListNode(int x) : val(x), next(nullptr)
    {
    }

    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }

    ~ListNode()
    {
        delete next;
    }
};

ListNode* CreateList(const std::vector<int>& values);

std::vector<int> ListToVector(ListNode* list);

