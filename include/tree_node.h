#pragma once

struct MyTreeNode
{
    int val;
    MyTreeNode* left;
    MyTreeNode* right;

    explicit MyTreeNode(int x = 0) : val(x), left(nullptr), right(nullptr)
    {}

    MyTreeNode(int x, MyTreeNode* left, MyTreeNode* right) : val(x), left(left), right(right)
    {}
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {}
};

