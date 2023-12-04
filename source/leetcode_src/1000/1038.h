#pragma once

#include <queue>

#include "include/tree_node.h"

namespace leetcode_1038{
class Solution
{
public:
    TreeNode* bstToGst(TreeNode* root)
    {
        std::queue<TreeNode*> nodes;
        RightRootLeft(root, nodes);
        int res{ 0 };
        while (!nodes.empty())
        {
            TreeNode* node = nodes.front();
            nodes.pop();
            auto temp = node->val;
            node->val += res;
            res += temp;
        }
        return root;
    }

    void RightRootLeft(TreeNode* root, std::queue<TreeNode*>& nodes)
    {
        if (root == nullptr)
            return;

        RightRootLeft(root->right, nodes);
        nodes.push(root);
        RightRootLeft(root->left, nodes);
    }
};
}
