#ifndef LEETCODE_CC_123_H
#define LEETCODE_CC_123_H

#include <vector>
#include <iostream>

namespace Leetcode_123
{
    class Solution
    {
    public:
        int maxProfit(std::vector<int>& prices)
        {
            auto dp = std::vector<std::vector<int>>(prices.size(), std::vector<int>(4, 0));
            dp[0][0] = dp[0][2] = -prices[0];
            dp[0][1] = dp[0][3] = 0;
            for (int i = 1; i < prices.size(); i++)
            {
                auto& now = dp[i];
                auto& pre = dp[i - 1];
                auto price = prices[i];

                now[0] = std::max(pre[0], -price);
                now[1] = std::max(pre[1], pre[0] + price);
                now[2] = std::max(pre[2], pre[1] - price);
                now[3] = std::max(pre[3], pre[2] + price);
            }

            return (*(dp.end() - 1))[3];
        }
    };
}
#endif //LEETCODE_CC_123_H
