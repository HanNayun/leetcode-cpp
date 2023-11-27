#ifndef LEETCODE_297_H
#define LEETCODE_297_H

#include "include/tree_node.h"

#include <list>
#include <string>

namespace Leetcode_297
{
    class Codec
    {
    public:

        // Encodes a tree to a single string.
        std::string serialize(TreeNode* root)
        {
            std::string res;
            RSerialize(res, root);
            return res;
        }

        void RSerialize(std::string& res, TreeNode* root)
        {
            if (root == nullptr)
            {
                res += "null,";
                return;
            }

            res += std::to_string(root->val) + ",";
            RSerialize(res, root->left);
            RSerialize(res, root->right);
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(const std::string& data)
        {
            std::list<std::string> data_list;
            std::string str;
            for (auto& c: data)
            {
                if (c == ',')
                {
                    data_list.push_back(str);
                    str.clear();
                }
                else
                {
                    str.push_back(c);
                }
            }

            if (!str.empty())
            {
                data_list.push_back(str);
                str.clear();
            }

            return RDeserialize(data_list);

        }

        TreeNode* RDeserialize(std::list<std::string>& data_list)
        {
            if (data_list.front() == "null")
            {
                data_list.erase(data_list.begin());
                return nullptr;
            }

            auto root = new TreeNode(std::stoi(data_list.front()));
            data_list.erase(data_list.begin());
            root->left = RDeserialize(data_list);
            root->right = RDeserialize(data_list);
            return root;
        }
    };

}
#endif //LEETCODE_297_H
