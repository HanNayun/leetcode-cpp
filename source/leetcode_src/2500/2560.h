#pragma once

#include <vector>

namespace Leetcode_2560 {
class Solution
{
public:
    int minCapability(std::vector<int>& nums, int k)
    {
        auto lower = *std::min_element(nums.begin(), nums.end());
        auto upper = *std::max_element(nums.begin(), nums.end());

        while (lower <= upper)
        {
            auto middle = (upper - lower) / 2 + lower;
            auto visited = false;
            auto count = 0;
            for (auto num: nums)
            {
                if (num <= middle && !visited)
                {
                    visited = true;
                    count++;
                }
                else
                {
                    visited = false;
                }
            }

            if (count >= k)
                upper = middle - 1;
            else
                lower = middle + 1;
        }

        return lower;
    }
};
}

