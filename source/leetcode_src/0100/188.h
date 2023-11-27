#ifndef LEETCODE_CC_188_H
#define LEETCODE_CC_188_H

#include <vector>

namespace Leetcode_188
{
    class Solution
    {
    public:
        int maxProfit(int k, std::vector<int>& prices)
        {
            auto day = prices.size();
            auto dp = std::vector<std::vector<int>>(day, std::vector<int>(2 * k, 0));
            for (int i = 0; i < 2 * k; i++)
            {
                dp[0][i] = i % 2 == 0
                           ? -prices[0]
                           : 0;
            }

            for (int i = 1; i < day; i++)
            {
                auto& pre = dp[i - 1];
                auto& now = dp[i];
                auto price = prices[i];

                for (int j = 0; j < 2 * k; j++)
                {
                    auto pre_val = j == 0 ? 0 : pre[j - 1];
                    auto change = j % 2 == 0 ? -price : price;
                    now[j] = std::max(pre[j], pre_val + change);
                }
            }

            return (*(dp.end() - 1))[2 * k - 1];
        }
    };
}

#endif //LEETCODE_CC_188_H
