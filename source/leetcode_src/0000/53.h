#pragma once

#include <vector>

namespace leetcode_53 {
class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        auto dp = std::vector<int>(nums.size());
        dp[0] = nums[0];
        auto res = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
            res = std::max(res, dp[i]);
        }

        return res;
    }
};
}

