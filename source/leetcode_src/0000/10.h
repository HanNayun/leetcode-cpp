#pragma once

#include <string>
#include <vector>

namespace leetcode_10{
class Solution
{
public:
    bool isMatch(std::string src, std::string pattern)
    {
        auto m{ src.size() };
        auto n{ pattern.size() };
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                UpdateInfo(dp, src, pattern, i, j);

        return dp[m][n];
    }

    static void UpdateInfo(std::vector<std::vector<int>>& dp,
                           const std::string& src,
                           const std::string& pattern,
                           const int& i,
                           const int& j)
    {
        if (pattern[j - 1] == '*')
        {
            dp[i][j] |= dp[i][j - 2];
            if (IsMatch(src, pattern, i, j - 1)) dp[i][j] |= dp[i - 1][j];
        }
        else if (IsMatch(src, pattern, i, j))
        {
            dp[i][j] |= dp[i - 1][j - 1];
        }
    }

    static bool IsMatch(const std::string& src,
                        const std::string& pattern,
                        const int& i,
                        const int& j)
    {
        if (i == 0) return false;
        if (pattern[j - 1] == '.') return true;
        return src[i - 1] == pattern[j - 1];
    }
};
}
