#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

namespace leetcode_14{
class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        auto res{ strs[0] };
        for (int i = 1; i < strs.size(); ++i)
        {
            if (res.empty()) return res;
            res = GetCommonPrefix(res, strs[i]);
        }

        return res;
    }

    static std::string GetCommonPrefix(const std::string& str1, const std::string& str2)
    {
        auto len{ std::min(str1.size(), str2.size()) };
        auto res{ std::string{} };
        for (int i = 0; i < len; ++i)
        {
            if (str1[i] == str2[i]) res += str1[i];
            else break;
        }
        return res;
    }
};
}
