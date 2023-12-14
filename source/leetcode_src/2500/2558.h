#pragma once

#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

namespace Leetcode_2558 {
class Solution
{
public:
    long long pickGifts(std::vector<int>& gifts, int k)
    {
        auto heap{std::priority_queue<int>(gifts.begin(), gifts.end())};
        while (k > 0)
        {
            --k;
            auto v = heap.top();
            heap.pop();
            v = std::floor(std::sqrt(v));
            heap.push(v);
        }

        auto res{0ll};
        while (!heap.empty())
        {
            res += heap.top();
            heap.pop();
        }

        return res;
    }
};
}
