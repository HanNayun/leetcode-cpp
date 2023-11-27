#ifndef LEETCODE_CC_1749_H
#define LEETCODE_CC_1749_H

#include "vector"

namespace Leetcode_1749
{
    class Solution
    {
    public:
        int maxAbsoluteSum(std::vector<int>& nums)
        {
            auto max_sum = nums[0];
            auto min_sum = nums[0];
            auto min_sums = std::vector<int>(nums.size());
            min_sums[0] = nums[0];
            auto max_sums = std::vector<int>(nums.size());
            max_sums[0] = nums[0];

            for (int i = 1; i < nums.size(); i++)
            {
                max_sums[i] = std::max(nums[i], max_sums[i - 1] + nums[i]);
                max_sum = std::max(max_sum, max_sums[i]);

                min_sums[i] = std::min(nums[i], min_sums[i - 1] + nums[i]);
                min_sum = std::min(min_sum, min_sums[i]);
            }

            return std::max(std::abs(max_sum), std::abs(min_sum));
        }
    };
}

#endif //LEETCODE_CC_1749_H
