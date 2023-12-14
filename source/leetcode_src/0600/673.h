#pragma once

#include <vector>
#include <algorithm>

namespace Leetcode_673 {
class Solution
{
public:
    int findNumberOfLIS(std::vector<int>& nums)
    {
        auto dp{std::vector<int>(nums.size(), 1)};
        auto cnt{std::vector<int>(nums.size(), 1)};
        auto max_len{1};
        auto res{1};
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        cnt[i] += cnt[j];
                    }
                }

            }

            if (dp[i] > max_len)
            {
                max_len = dp[i];
                res = cnt[i];
            }
            else if (dp[i] == max_len)
            {
                res += cnt[i];
            }
        }

        return res;
    }
};
}
