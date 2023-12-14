#pragma once

#include <vector>

namespace Leetcode_344 {
class Solution
{
public:
    void reverseString(std::vector<char>& s)
    {
        auto left = 0;
        auto right = s.size() - 1;
        while (left < right)
        {
            auto temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--;
        }
    }
};
}

