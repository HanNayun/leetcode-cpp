#pragma once

#include <vector>

namespace leetcode_746 {
class Solution
{
public:
    int minCostClimbingStairs(std::vector<int>& cost)
    {
        int n{static_cast<int>(cost.size())};
        std::vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i)
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        return dp[n];
    }
};
}
