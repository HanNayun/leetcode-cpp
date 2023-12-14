#pragma once

#include <vector>
#include <queue>

namespace Leetcode_2530 {
class Solution
{
public:
    long long maxKelements(std::vector<int>& nums, int k)
    {
        auto res{0ll};
        auto heap{std::priority_queue<int>()};
        for (const auto& num: nums)
            heap.push(num);

        while (k--)
        {
            auto top{heap.top()};
            heap.pop();
            res += top;
            heap.push(std::ceil(top / 3.0));
        }

        return res;
    }
};
}
