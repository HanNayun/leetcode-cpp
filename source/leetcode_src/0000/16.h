#pragma once

#include <algorithm>
#include <vector>

namespace leetcode_16 {
class Solution
{
public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        auto result{nums[0] + nums[1] + nums[2]};
        auto len{static_cast<int>(nums.size())};
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1, k = len - 1; j < k;)
            {
                auto sum{nums[i] + nums[j] + nums[k]};
                if (sum == target)
                    return target;

                if (std::abs(sum - target) < std::abs(result - target))
                    result = sum;

                if (sum < target)
                    ++j;
                else
                    --k;
            }
        }

        return result;
    }
};
}
