#pragma once

#include <string>
#include <stack>

namespace leetcode_20
{
    class Solution
    {
    public:
        bool isValid(const std::string& s)
        {
            auto stack{std::stack<char>{}};
            for (const auto& c: s)
            {
                if (c == '(' || c == '[' || c == '{')
                {
                    stack.push(c);
                }
                else
                {
                    if (stack.empty()) return false;
                    if (c == ')' && stack.top() != '(') return false;
                    if (c == ']' && stack.top() != '[') return false;
                    if (c == '}' && stack.top() != '{') return false;
                    stack.pop();
                }
            }

            return stack.empty();
        }
    };
}