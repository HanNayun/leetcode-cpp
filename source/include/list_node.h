#pragma once

#include <vector>

class ListNode
{
public:
    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}

    ~ListNode()
    {
        delete next;
    }

    int val;
    ListNode* next;
};

ListNode* CreateList(const std::vector<int>& values);

std::vector<int> ListToVector(ListNode* list);

