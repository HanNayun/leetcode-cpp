#pragma once

#include <vector>

namespace Leetcode_714 {
using std::vector;

class Solution
{
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        auto day = prices.size();
        auto dp = vector<vector<int>>(day, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < day; ++i)
        {
            auto price = prices[i];
            auto& pre = dp[i - 1];
            auto& now = dp[i];
            now[0] = std::max(pre[0], pre[1] + price - fee);
            now[1] = std::max(pre[1], pre[0] - price);
        }

        return std::max(dp[day - 1][0], dp[day - 1][1]);

    }
};
}
