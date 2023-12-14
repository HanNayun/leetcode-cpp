#pragma once

#include <algorithm>

#include <vector>

namespace leetcode_2656 {
class Solution
{
public:
    int maximizeSum(const std::vector<int>& nums, int k)
    {
        return std::ranges::max(nums) * k + (k * k - k) / 2;
    }
};
}
