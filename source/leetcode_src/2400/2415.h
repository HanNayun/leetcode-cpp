#pragma once

#include "tree_node.h"

#include <queue>

namespace leetcode_2415 {
class Solution
{
public:
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        std::queue<TreeNode*> nodes;
        bool is_reverse{true};
        nodes.emplace(root);
        while (!nodes.empty())
        {
            auto num{nodes.size()};
            std::vector<TreeNode*> level_nodes;
            while (num > 0)
            {
                --num;
                auto node{nodes.front()};
                nodes.pop();
                level_nodes.emplace_back(node);

                if (node->left != nullptr)
                    nodes.emplace(node->left);
                if (node->right != nullptr)
                    nodes.emplace(node->right);
            }

            if (is_reverse)
            {
                int left{0};
                int right{static_cast<int>(level_nodes.size()) - 1};
                while (left <= right)
                {
                    auto left_node{level_nodes[left]};
                    auto right_node{level_nodes[right]};

                    if (left_node->left == nullptr)
                        break;

                    if (left == right)
                    {
                        std::swap(left_node->left->val, left_node->right->val);
                    }
                    else
                    {
                        std::swap(left_node->left->val, right_node->right->val);
                        std::swap(left_node->right->val, right_node->left->val);
                    }

                    ++left;
                    --right;
                }
            }

            is_reverse = !is_reverse;
        }

        return root;
    }
};
}