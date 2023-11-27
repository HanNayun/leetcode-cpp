#ifndef LEETCODE_CC_617_H
#define LEETCODE_CC_617_H

#include "include/tree_node.h"

#include <vector>
#include <queue>

namespace Leetcode_617
{
    class Solution
    {
    public:
        MyTreeNode* mergeTrees(MyTreeNode* root1, MyTreeNode* root2)
        {
            if (root1 == nullptr)
            {
                return root2;
            }

            if (root2 == nullptr)
            {
                return root1;
            }

            auto merged = new MyTreeNode(root1->val + root2->val);
            merged->left = mergeTrees(root1->left, root2->left);
            merged->right = mergeTrees(root1->right, root2->right);

            return merged;
        }

    };
}

#endif //LEETCODE_CC_617_H
