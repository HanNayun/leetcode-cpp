#pragma once

#include <vector>
#include <unordered_map>

namespace leetcode_1{
class Solution
{
public:
    std::vector<int> twoSum(const std::vector<int>& nums, const int target)
    {
        const auto n{ nums.size() };
        auto index{ std::unordered_map<int, int>{} };
        for (int i = 0; i < n; ++i)
        {
            if (index[target - nums[i]])
                return std::vector<int>{ index[target - nums[i]] - 1, i };
            index[nums[i]] = i + 1;
        }

        return std::vector<int>{};
    }
};
}
