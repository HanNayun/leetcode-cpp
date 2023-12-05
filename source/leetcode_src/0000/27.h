#pragma once

#include <vector>

namespace leetcode_27{
class Solution
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        int p{ static_cast<int>(nums.size()) };
        if (p == 0)
            return 0;

        for (int i = 0; i < p; ++i)
        {
            if (nums[i] == val)
            {
                while (p == nums.size() || p > i && nums[p] == val)
                    --p;

                std::swap(nums[i], nums[p]);
            }
        }

        return p;
    }
};
}
