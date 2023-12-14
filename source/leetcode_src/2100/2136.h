#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

namespace Leetcode_2136 {
class Solution
{
public:
    int earliestFullBloom(std::vector<int>& plant_time, std::vector<int>& grow_time)
    {
        auto flowers = std::vector<int>(plant_time.size());
        std::iota(flowers.begin(), flowers.end(), 0);
        std::sort(flowers.begin(), flowers.end(), [&](int a, int b)
        {
            auto first_a = plant_time[a] + std::max(grow_time[a], plant_time[b] + grow_time[b]);
            auto first_b = plant_time[b] + std::max(grow_time[b], plant_time[a] + grow_time[a]);

            return first_a < first_b;
        });

        auto time = 0;
        auto res = 0;
        for (auto idx: flowers)
        {
            time += plant_time[idx];
            res = std::max(res, time + grow_time[idx]);
        }

        return res;
    }
};
}
