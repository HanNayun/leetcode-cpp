#pragma once

#include <algorithm>

#ifndef LEETCODE_2656_H
#define LEETCODE_2656_H

#include <vector>

namespace leetcode_2656
{
    class Solution
    {
    public:
        int maximizeSum(const std::vector<int>& nums, int k)
        {
            return std::ranges::max(nums) * k + (k * k - k) / 2;
        }
    };
}
#endif //LEETCODE_2656_H
