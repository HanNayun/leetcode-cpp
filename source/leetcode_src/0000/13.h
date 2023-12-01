#pragma once

#include <string>
#include <unordered_map>
#include <iostream>

namespace leetcode_13{
class Solution
{
public:
    int romanToInt(const std::string& s)
    {
        auto len{ s.size() };
        auto res{ 0 };
        for (int i = 0; i < len; ++i)
        {
            if (i + 1 < len && roman_to_int_[s[i]] < roman_to_int_[s[i + 1]]) res -= roman_to_int_[s[i]];
            else res += roman_to_int_[s[i]];
        }

        return res;
    }

private:
    std::unordered_map<char, int> roman_to_int_{
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 }
    };
};
}
