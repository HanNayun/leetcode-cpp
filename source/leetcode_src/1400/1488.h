#pragma once

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

namespace Leetcode_1488 {
class Solution
{
public:
    std::vector<int> avoidFlood(std::vector<int>& rains)
    {
        std::vector<int> res(rains.size(), 1);
        std::vector<int> dry_day{};
        std::unordered_map<int, int> lake_last_rain_day{};
        for (int i = 0; i < res.size(); i++)
        {
            auto rain{rains[i]};
            if (rain == 0)
            {
                dry_day.push_back(i);
                continue;
            }

            res[i] = -1;
            if (!lake_last_rain_day.contains(rain))
            {
                lake_last_rain_day[rain] = i;
                continue;
            }

            auto day = FindFirstMoreThanK(dry_day, lake_last_rain_day[rain]);
            if (day == dry_day.end())
                return {};
            
            res[*day] = rain;
            dry_day.erase(day);
            lake_last_rain_day[rain] = i;
        }

        return res;
    }

    static std::vector<int>::iterator FindFirstMoreThanK(std::vector<int>& day, int k)
    {
        auto start{day.begin()};
        auto end{day.end()};

        while (start < end)
        {
            auto mid = start + (end - start) / 2;
            if (*mid < k)
                start = mid + 1;
            else
                end = mid;
        }

        return start;
    }
};
}
