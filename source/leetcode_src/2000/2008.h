#pragma once

#include <vector>
#include <ranges>
#include <unordered_map>
#include <algorithm>

namespace leetcode_8{
class Solution
{
public:
    long long maxTaxiEarnings(int n, std::vector<std::vector<int>>& rides)
    {
        std::vector<long long> dp(n + 1, 0);
        std::unordered_map<int, std::vector<std::vector<int>>> ride_map(n + 1);
        for (const auto& ride: rides)
            ride_map[ride[1]].push_back(ride);

        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1];
            for (const auto& ride: ride_map[i])
                dp[i] = std::max(dp[i], dp[ride[0]] + ride[1] - ride[0] + ride[2]);
        }

        return dp[n];
    }
};
}
