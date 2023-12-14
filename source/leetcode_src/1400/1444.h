#pragma once

#include <string>
#include <vector>

namespace Leetcode_1444 {
class Solution
{
public:
    const int MOD = 1e9 + 7;

    int ways(std::vector<std::string>& pizza, int k)
    {
        auto m = pizza.size();
        auto n = pizza[0].size();

        auto apples = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1));
        std::vector<std::vector<std::vector<int>>> dp(k + 1,
                                                      std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1)));

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                apples[i][j] = apples[i][j + 1] + apples[i + 1][j] - apples[i + 1][j + 1] + (pizza[i][j] == 'A');
                dp[1][i][j] = apples[i][j] > 0 ? 1 : 0;
            }
        }

        for (int ki = 2; ki <= k; ki++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    // horizontal cut
                    for (int i2 = i + 1; i2 < m; i2++)
                        if (apples[i][j] > apples[i2][j])
                            dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i2][j]) % MOD;
                    
                    // vertical cut
                    for (int j2 = j + 1; j2 < n; j2++)
                        if (apples[i][j] > apples[i][j2])
                            dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i][j2]) % MOD;
                }
            }
        }
        return dp[k][0][0];
    }
};
}

