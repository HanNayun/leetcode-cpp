#pragma once

#include <vector>
#include <unordered_map>

namespace Leetcode_1726 {
class Solution
{
public:
    int tupleSameProduct(std::vector<int>& nums)
    {
        std::unordered_map<int, int> product_map{};
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                auto product{nums[i] * nums[j]};
                ++product_map[product];
            }
        }

        int res{0};
        for (const auto& map: product_map)
        {
            res += map.second * (map.second - 1) * 4;
        }

        return res;
    }
};
}
