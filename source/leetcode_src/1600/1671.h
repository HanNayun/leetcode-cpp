#pragma once

#include <algorithm>
#include <vector>
#include <ranges>

namespace leetcode_1671 {
class Solution
{
public:
    int minimumMountainRemovals(std::vector<int>& nums)
    {
        auto n{nums.size()};
        auto prefix{GetLISArray(nums)};
        std::ranges::reverse(nums);
        auto suffix{GetLISArray(nums)};
        std::ranges::reverse(suffix);
        auto max{0};
        for (int i = 0; i < n; ++i)
            if (prefix[i] > 1 && suffix[i] > 1)
                max = std::max(max, prefix[i] + suffix[i] - 1);
        return n - max;
    }

private:
    std::vector<int> GetLISArray(const std::vector<int>& nums)
    {
        auto n{nums.size()};
        std::vector<int> dp(n, 1);
        std::vector<int> queue;
        for (int i = 0; i < n; ++i)
        {
            auto idx = std::lower_bound(queue.begin(), queue.end(), nums[i]) - queue.begin();
            if (idx == queue.size())
            {
                queue.emplace_back(nums[i]);
                dp[i] = queue.size();
            }
            else
            {
                queue[idx] = nums[i];
                dp[i] = idx + 1;
            }
        }
        return dp;
    }
};
}