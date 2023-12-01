#pragma once

#include <vector>

class ListNode
{
public:
    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(const int x, ListNode* next) : val(x), next(next) {}

    ~ListNode();

    static ListNode* CreateList(const std::vector<int>& values);

    static std::vector<int> ListToVector(ListNode* list);

    int val;
    ListNode* next;
};



