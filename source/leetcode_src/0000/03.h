#pragma once

#include <string>
#include <unordered_map>

namespace leetcode_03{
class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        auto left{ 0 };
        auto right{ 0 };
        int max_len{ 0 };
        auto last_index{ std::unordered_map<char, int>{} };

        while (right < s.size())
        {
            auto c{ s[right] };
            if (last_index.contains(c) && last_index[c] >= left)
            {
                max_len = std::max(max_len, right - left);
                left = last_index[c] + 1;
            }
            else if (right == s.size() - 1)
            {
                max_len = std::max(max_len, right - left + 1);
            }

            last_index[c] = right;
            ++right;
        }

        return max_len;
    }
};
}
