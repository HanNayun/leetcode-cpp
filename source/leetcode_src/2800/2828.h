#pragma once

#include <vector>
#include <string>

namespace leetcode_2828 {
class Solution
{
public:
    bool isAcronym(std::vector<std::string>& words, std::string s)
    {
        if (s.length() != words.size())
            return false;

        for (int i = 0; i < s.length(); i++)
            if (s[i] != words[i][0])
                return false;

        return true;
    }
};
}
