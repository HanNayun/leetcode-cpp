#pragma once

#include <vector>

namespace leetcode_2760
{
    class Solution
    {
    public:
        int longestAlternatingSubarray(std::vector<int>& nums, int threshold)
        {
            auto len{nums.size()};
            auto res{0};
            auto dp{0};
            for (int i = static_cast<int>(len - 1); i >= 0; --i)
            {
                if (nums[i] > threshold)
                    dp = 0;
                else if (i == len - 1 || nums[i] % 2 ^ nums[i + 1] % 2)
                    dp++;
                else
                    dp = 1;

                if (nums[i] % 2 == 0)
                    res = std::max(res, dp);
            }


            return res;
        }
    };
}