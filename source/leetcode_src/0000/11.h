#pragma once

#include <vector>

namespace leetcode_11 {
class Solution
{
public:
    int maxArea(std::vector<int>& height)
    {
        auto max{0};
        auto size{height.size()};
        auto left{0};
        auto right{size - 1};
        while (left < right)
        {
            auto area{(right - left) * std::min(height[left], height[right])};
            if (area > max)
                max = area;
            
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }

        return max;
    }
};
}
