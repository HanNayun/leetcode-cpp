#ifndef LEETCODE_CC_337_H
#define LEETCODE_CC_337_H

#include "include/tree_node.h"

#include <unordered_map>

namespace Leetcode_337
{
    class Solution
    {
    private:
        std::unordered_map<MyTreeNode*, int> _selected;
        std::unordered_map<MyTreeNode*, int> _unselected;

        void Dfs(MyTreeNode* node)
        {
            if (!node)
            {
                return;
            }

            auto left = node->left;
            auto right = node->right;

            Dfs(left);
            Dfs(right);

            _selected[node] = _unselected[left] + _unselected[right] + node->val;
            _unselected[node] =
                    std::max(_selected[left], _unselected[left]) + std::max(_selected[right], _unselected[right]);
        }

    public:
        int rob(MyTreeNode* root)
        {
            Dfs(root);
            return std::max(_selected[root], _unselected[root]);
        }
    };
}

#endif //LEETCODE_CC_337_H
