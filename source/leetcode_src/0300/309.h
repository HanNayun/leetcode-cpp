#pragma once

#include <vector>

namespace Leetcode_309 {
class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        auto day = prices.size();
        auto own = std::vector<int>(day, 0);
        auto buy = std::vector<int>(day, 0);
        auto cooldown = std::vector<int>(day, 0);
        own[0] = -prices[0];
        buy[0] = 0;
        cooldown[0] = 0;

        for (int i = 1; i < day; ++i)
        {
            auto price = prices[i];
            own[i] = std::max(own[i - 1], buy[i - 1] - price);
            cooldown[i] = own[i - 1] + price;
            buy[i] = std::max(buy[i - 1], cooldown[i - 1]);
        }

        return std::max(buy[day - 1], cooldown[day - 1]);
    }
};
}
