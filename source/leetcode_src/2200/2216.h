#pragma once

#include <vector>

namespace leetcode_2216
{
    class Solution
    {
    public:
        int minDeletion(std::vector<int>& nums)
        {
            auto n{static_cast<int>(nums.size())};
            auto res{0};
            auto is_even_digit{1};
            for (int i = 0; i + 1 < n; ++i)
            {
                if (is_even_digit && nums[i] == nums[i + 1])
                    ++res;
                else
                    is_even_digit = !is_even_digit;
            }

            return res + (n - res) % 2;
        }
    };
}