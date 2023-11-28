#ifndef LEETCODE_300_H
#define LEETCODE_300_H

#include <vector>
#include <algorithm>

namespace Leetcode_300
{
    class Solution
    {
    public:
        int lengthOfLIS(std::vector<int>& nums)
        {
            auto dp{ std::vector<int>(nums.size(), 1) };
            for (int i = 1; i < nums.size(); i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (nums[i] > nums[j])
                    {
                        dp[i] = std::max(dp[i], dp[j] + 1);
                    }
                }
            }

            return *std::max_element(dp.begin(), dp.end());
        }
    };
}
#endif //LEETCODE_300_H