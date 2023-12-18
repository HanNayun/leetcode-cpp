#pragma once

#include <vector>

namespace leetcode_162 {
class Solution
{
public:
    int findPeakElement(std::vector<int>& nums)
    {
        int n{static_cast<int>(nums.size())};
        int left{0};
        int right{n - 1};

        auto get = [&nums](int i)
        {
            if (i < 0 || i >= nums.size())
                return std::pair{0, 0};

            return std::pair{1, nums[i]};
        };

        auto less = [&nums, &get](int a, int b)
        {
            auto val_a = get(a);
            auto val_b = get(b);
            if (val_a.first != val_b.first)
                return val_a.first < val_b.first;
            return val_a.second < val_b.second;
        };

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (less(mid - 1, mid) && less(mid + 1, mid))
                return mid;

            if (less(mid, mid + 1))
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};
}