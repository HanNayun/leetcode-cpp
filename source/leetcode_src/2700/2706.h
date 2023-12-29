#pragma once

#include <vector>

namespace leetcode_2706 {
class Solution
{
public:
    int buyChoco(std::vector<int>& prices, int money)
    {
        int min1{std::numeric_limits<int>::max()};
        int min2{std::numeric_limits<int>::max()};
        for (const auto& price: prices)
        {
            if (price < min1)
            {
                min2 = min1;
                min1 = price;
            }
            else if (price < min2)
            {
                min2 = price;
            }
        }

        auto cost{min1 + min2};
        return cost > money ? money
                            : money - cost;
    }
};
}
