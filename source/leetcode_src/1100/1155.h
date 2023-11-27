#ifndef LEETCODE_1155_H
#define LEETCODE_1155_H

#include <vector>

namespace Leetcode_1155
{
    class Solution
    {
    public:
        int numRollsToTarget(int n, int k, int target)
        {
            constexpr auto MOD{ 1000000007 };
            auto dp{ std::vector<std::vector<int>>(n + 1, std::vector<int>(target + 1, 0)) };
            for (int i{ 1 }; i <= target; ++i)
            {
                if (i <= k)
                {
                    dp[1][i] = 1;
                }
            }

            for (int i{ 2 }; i <= n; ++i)
            {
                for (int j{ 1 }; j <= target; ++j)
                {
                    for (int m{ 1 }; m <= k; ++m)
                    {
                        if (j - m >= 0)
                        {
                            dp[i][j] = (dp[i][j] + dp[i - 1][j - m]) % MOD;
                        }
                    }
                }
            }

            return dp[n][target];
        }
    };
}
#endif //LEETCODE_1155_H
