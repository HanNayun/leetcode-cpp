#pragma once

#include <vector>

namespace leetcode_1599 {
class Solution
{
public:
    int minOperationsMaxProfit(std::vector<int>& customers, int boarding_cost, int running_cost)
    {
        auto n{customers.size()};
        std::vector<long long> profit_list(n + 1, 0);
        auto wait_customers{0};
        auto entered_customers{0};

        auto max_profit{-1ll};
        auto res{-1};
        auto i{1};

        while (wait_customers || i <= n)
        {
            if (i <= n)
                wait_customers += customers[i - 1];

            auto new_enter{wait_customers > 4 ? 4 : wait_customers};
            entered_customers += new_enter;
            wait_customers -= new_enter;

            auto profit{boarding_cost * entered_customers - running_cost * i};
            if (profit > max_profit)
            {
                max_profit = profit;
                res = i;
            }

            ++i;
        }


        if (max_profit > 0)
            return res;
        return -1;
    }
};
}
