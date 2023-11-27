#pragma once

#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <ranges>

namespace leetcode_331
{
    struct MyTreeNode
    {
        int leaf;

        MyTreeNode()
        {
            leaf = 0;
        }
    };

    class Solution
    {
    public:
        bool isValidSerialization(std::string preorder)
        {
            auto node_list = std::vector<MyTreeNode*>();
            auto stack = std::stack<MyTreeNode*>();

            std::vector<std::string> str_list = Split(std::move(preorder), ",");

            auto is_first = true;
            for (const auto& str: str_list)
            {
                if (is_first)
                {
                    is_first = false;
                }
                else
                {
                    if (stack.empty())
                        return false;

                    auto top = stack.top();
                    top->leaf++;

                    if (top->leaf == 2)
                        stack.pop();
                }

                if (str != "#")
                {
                    auto node = new MyTreeNode();
                    stack.emplace(node);
                    node_list.emplace_back(node);
                }
            }

            return std::ranges::all_of(node_list, [](const auto& node)
            {
                return node->leaf == 2;
            });
        }

        std::vector<std::string> Split(std::string str, std::string delim)
        {
            auto res = std::vector<std::string>();
            auto pos = str.find(delim);
            while (pos != std::string::npos)
            {
                res.push_back(str.substr(0, pos));
                str = str.substr(pos + 1);
                pos = str.find(delim);
            }

            res.push_back(str);
            return res;
        }
    };
}
