#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

namespace leetcode_1962 {
class Solution
{
public:
    int minStoneSum(std::vector<int>& piles, int k)
    {
        std::vector<int> v(piles);
        std::make_heap(v.begin(), v.end());

        while (k > 0)
        {
            auto max{v.front()};
            std::pop_heap(v.begin(), v.end());
            v.pop_back();

            auto half{max / 2};
            auto remain{max - half};
            v.push_back(remain);
            std::push_heap(v.begin(), v.end());

            k--;
        }

        return std::accumulate(v.begin(), v.end(), 0);
    }
};
}