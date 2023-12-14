#pragma once

#include <vector>

namespace Leetcode_121 {

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        auto min_price = prices[0];
        auto res = 0;
        for (auto price: prices)
        {
            res = std::max(res, price - min_price);
            if (price < min_price)
                min_price = price;
        }

        return res;
    }
};
}
