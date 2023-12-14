#pragma once

#include "tree_node.h"

namespace leetcode_1038 {
class Solution
{
public:
    TreeNode* bstToGst(TreeNode* root)
    {
        int res{0};
        RightRootLeft(root, res);
        return root;
    }

    void RightRootLeft(TreeNode* root, int& sum)
    {
        if (root == nullptr)
            return;

        RightRootLeft(root->right, sum);
        sum += root->val;
        root->val = sum;
        RightRootLeft(root->left, sum);
    }
};
}
