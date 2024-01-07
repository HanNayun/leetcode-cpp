#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace leetcode_383 {
class Solution
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        std::vector<int> count(26, 0);

        std::ranges::for_each(ransomNote, [&count](char ch)
        { --count[ch - 'a']; });
        std::ranges::for_each(magazine, [&count](char ch)
        { ++count[ch - 'a']; });

        return std::ranges::all_of(count, [](int c)
        { return c >= 0; });
    }
};
}