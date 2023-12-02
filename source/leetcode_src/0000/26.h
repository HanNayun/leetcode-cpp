#pragma once

#include <vector>

namespace leetcode_26{
class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        int slow{ 0 };
        int fast{ 0 };
        while (fast < nums.size())
        {
            if (nums[slow] != nums[fast])
                nums[++slow] = nums[fast];
            ++fast;
        }

        return ++slow;
    }
};
}
