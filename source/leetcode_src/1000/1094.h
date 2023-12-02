#pragma once

#include <algorithm>
#include <vector>

namespace leetcode_1094{
class Solution
{
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity)
    {
        int max_to{ 0 };
        std::ranges::for_each(trips, [&max_to](const auto& trip) { max_to = std::max(max_to, trip[2]); });

        std::vector<int> diff(max_to + 1, 0);
        for (const auto& trip: trips)
        {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }

        int now_capacity{ 0 };
        for (const auto& d: diff)
        {
            now_capacity += d;
            if (now_capacity > capacity)
                return false;
        }

        return true;
    }
};
}
