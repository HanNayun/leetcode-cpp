#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode_828
{
    class Solution
    {
    public:
        int uniqueLetterString(const std::string& s)
        {
            auto indexes{std::unordered_map<char, std::vector<int>>{}};
            for (int i = 0; i < s.size(); ++i)
                indexes[s[i]].emplace_back(i);

            auto res{0};
            for (auto& [_, index]: indexes)
            {
                index.insert(index.begin(), -1);
                index.emplace_back(s.size());
                for (int i = 1; i < index.size() - 1; ++i)
                    res += (index[i] - index[i - 1]) * (index[i + 1] - index[i]);
            }

            return res;
        }
    };
}