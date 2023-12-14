#pragma once

#include "tree_node.h"

#include <stack>
#include <vector>

namespace leetcode_1457 {
class Solution
{
public:
    int pseudoPalindromicPaths(TreeNode* root)
    {
        auto res{0};
        auto stack{std::vector<TreeNode*>{}};
        auto nums{std::vector<int>(10, 0)};
        auto odd_num{0};
        Dfs(stack, nums, odd_num, res, root);
        return res;

    }

    void Dfs(std::vector<TreeNode*>& path,
             std::vector<int>& nums,
             int& odd_num,
             int& res,
             TreeNode* node)
    {
        if (node == nullptr)
            return;

        path.push_back(node);
        odd_num += ++nums[node->val] % 2 ? 1 : -1;

        if (!IsLeafNode(node))
        {
            Dfs(path, nums, odd_num, res, node->left);
            Dfs(path, nums, odd_num, res, node->right);
        }
        else
        {
            res += odd_num <= 1;
        }

        auto last_node = path.back();
        odd_num += --nums[last_node->val] % 2 ? 1 : -1;
        path.pop_back();
    }

    static bool IsLeafNode(const TreeNode* node)
    {
        if (node == nullptr)
            return false;
        return node->left == nullptr && node->right == nullptr;
    }
};
}
