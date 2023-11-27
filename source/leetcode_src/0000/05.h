#pragma once

#include <string>
#include <vector>

namespace leetcode_05
{
    class Solution
    {
    public:
        std::string longestPalindrome(std::string s)
        {
            auto n = s.size();

            if (n < 2) return s;

            auto dp{std::vector<std::vector<bool>>(n, std::vector<bool>(n, false))};
            for (int i = 0; i < n; ++i)
                dp[i][i] = true;

            auto max_len{1};
            auto start{0};
            for (int len = 2; len <= n; ++len)
            {
                for (int i = 0; i <= n - len; ++i)
                {
                    int j = i + len - 1;

                    if (s[i] == s[j] && (len < 3 || dp[i + 1][j - 1]))
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;

                    if (len > max_len && dp[i][j])
                    {
                        max_len = len;
                        start = i;
                    }
                }
            }

            return s.substr(start, max_len);
        }
    };
}
