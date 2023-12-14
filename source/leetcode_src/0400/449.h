#pragma once

#include "tree_node.h"

#include <stack>
#include <string>
#include <vector>

namespace Leetcode_449 {
class Codec
{
public:
    std::string serialize(TreeNode* root)
    {
        std::string res;
        std::vector<int> arr;
        PostOrder(root, arr);
        if (arr.empty())
        {
            return res;
        }

        for (int i = 0; i < arr.size() - 1; i++)
        {
            res.append(std::to_string(arr[i]) + ",");
        }
        res.append(std::to_string(arr.back()));
        return res;
    }

    TreeNode* deserialize(const std::string& data)
    {
        if (data.empty())
        {
            return nullptr;
        }
        std::vector<std::string> arr = Split(data, ',');
        std::stack<int> st;
        for (auto& str: arr)
        {
            st.emplace(std::stoi(str));
        }
        return Construct(INT_MIN, INT_MAX, st);
    }

private:
    std::vector<std::string> Split(const std::string& str, char dec)
    {
        int pos = 0;
        int start = 0;
        std::vector<std::string> res;
        while (pos < str.size())
        {
            while (pos < str.size() && str[pos] == dec)
            {
                pos++;
            }
            start = pos;
            while (pos < str.size() && str[pos] != dec)
            {
                pos++;
            }
            if (start < str.size())
            {
                res.emplace_back(str.substr(start, pos - start));
            }
        }
        return res;
    }

    void PostOrder(TreeNode* root, std::vector<int>& arr)
    {
        if (root == nullptr)
        {
            return;
        }

        PostOrder(root->left, arr);
        PostOrder(root->right, arr);
        arr.emplace_back(root->val);
    }

    TreeNode* Construct(int lower, int upper, std::stack<int>& st)
    {
        if (st.empty() || st.top() < lower || st.top() > upper)
        {
            return nullptr;
        }

        int val = st.top();
        st.pop();
        auto* root = new TreeNode(val);
        root->right = Construct(val, upper, st);
        root->left = Construct(lower, val, st);
        return root;
    }
};

}
