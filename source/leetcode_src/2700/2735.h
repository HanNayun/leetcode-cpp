#pragma once

#include <numeric>
#include <vector>
#include <ranges>
#include <algorithm>

namespace leetcode_2735 {
class Solution
{
public:
    long long minCost(std::vector<int>& nums, int x)
    {
        auto len{nums.size()};
        std::vector<std::vector<long long>> cost(len, std::vector<long long>(len, 0));

        for (int k = 0; k < len; ++k)
        {
            for (int i = 0; i < len; ++i)
            {
                if (k == 0)
                    cost[k][i] = nums[i];
                else
                {
                    auto j = (i + k) % len;
                    cost[k][i] = std::min(cost[k - 1][i], static_cast<long long>(nums[j]));
                }
            }
        }

        auto min_cost{std::numeric_limits<long long>::max()};
        for (int k = 0; k < len; ++k)
        {
            auto sum{std::accumulate(std::begin(cost[k]), std::end(cost[k]), 0ll)};
            min_cost = std::min(min_cost, sum + static_cast<long long>(x) * k);
        }

        return min_cost;
    }
};
}
