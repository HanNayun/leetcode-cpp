#pragma once


#include <vector>

namespace Leetcode_122 {
class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        auto day = prices.size();
        int res = 0;
        for (int i = 1; i < day; i++)
            res += std::max(0, prices[i] - prices[i - 1]);
        return res;
    }
};
}

