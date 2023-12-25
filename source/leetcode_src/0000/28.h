#pragma once

#include <string>
#include <vector>

namespace leetcode_28 {
class Solution
{
public:
    int strStr(const std::string& haystack, const std::string& needle)
    {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0)
            return 0;

        std::vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++)
        {
            while (j > 0 && needle[i] != needle[j])
                j = pi[j - 1];

            if (needle[i] == needle[j])
                j++;

            pi[i] = j;
        }

        for (int i = 0, j = 0; i < n; i++)
        {
            while (j > 0 && haystack[i] != needle[j])
                j = pi[j - 1];

            if (haystack[i] == needle[j])
                j++;

            if (j == m)
                return i - m + 1;
        }
        return -1;
    }
};
}
