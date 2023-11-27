#pragma once

#include <vector>

namespace leetcode_689
{
    class Solution
    {
    public:
        std::vector<int> maxSumOfThreeSubarrays(std::vector<int>& nums, int k)
        {
            auto res = std::vector<int>(3, 0);

            auto sum1 = 0;
            auto sum1_max = 0;
            auto sum1_idx = 0;

            auto sum2 = 0;
            auto sum12_max = 0;
            auto sum12_idx1 = 0;
            auto sum12_idx2 = 0;

            auto sum3 = 0;
            auto sum3_max = 0;

            const auto len = nums.size();
            for (int i = 2 * k; i < len; ++i)
            {
                sum1 += nums[i - 2 * k];
                sum2 += nums[i - k];
                sum3 += nums[i];

                if (i >= 3 * k - 1)
                {
                    if (sum1 > sum1_max)
                    {
                        sum1_max = sum1;
                        sum1_idx = i - 3 * k + 1;
                    }

                    if (sum2 + sum1_max > sum12_max)
                    {
                        sum12_max = sum2 + sum1_max;
                        sum12_idx1 = sum1_idx;
                        sum12_idx2 = i - 2 * k + 1;
                    }

                    if (sum3 + sum12_max > sum3_max)
                    {
                        sum3_max = sum3 + sum12_max;
                        res[0] = sum12_idx1;
                        res[1] = sum12_idx2;
                        res[2] = i - k + 1;
                    }

                    sum1 -= nums[i - 3 * k + 1];
                    sum2 -= nums[i - 2 * k + 1];
                    sum3 -= nums[i - k + 1];
                }
            }

            return res;
        }
    };
}