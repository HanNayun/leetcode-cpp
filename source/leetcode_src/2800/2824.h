#pragma once

#include <algorithm>
#include <vector>

namespace leetcode_2824
{
    class Solution
    {
    public:
        int countPairs(std::vector<int>& nums, int target)
        {
            std::sort(nums.begin(), nums.end());
            auto res{0};
            auto len{nums.size()};
            for (int i = 0; i < len - 1; ++i)
            {
                auto v{target - nums[i]};
                auto k{static_cast<int>(std::lower_bound(nums.begin() + i + 1, nums.end(), v) - nums.begin())};
                res += k - i - 1;
            }

            return res;
        }
    };
}
