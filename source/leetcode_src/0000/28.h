#pragma once

#include <string>

namespace leetcode_28 {
class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        auto n{haystack.size()};
        auto m{needle.size()};
        if (m > n)
            return -1;

        if (m == n)
            return haystack == needle ? 0 : -1;

        int left{0};
        int right{0};
        std::string temp;
        while (right < m)
        {
            temp += haystack[right];
            right++;
        }

        if (temp == needle)
            return left;

        while (right < n)
        {
            temp.erase(0, 1);
            temp += haystack[right];
            right++;
            left++;

            if (temp == needle)
                return left;


        }

        return -1;
    }
};
}
