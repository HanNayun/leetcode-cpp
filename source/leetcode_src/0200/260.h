#pragma once

#include <vector>

namespace Leetcode_260 {
class Solution
{
public:
    std::vector<int> singleNumber(std::vector<int>& nums)
    {
        auto xor_sum{0u};
        for (const auto& num: nums)
            xor_sum ^= num;

        auto xor_sum_last_bit{xor_sum & -xor_sum};
        auto num1{0u};
        auto num2{0u};
        for (const auto& num: nums)
        {
            if (num & xor_sum_last_bit)
                num1 ^= num;
            else
                num2 ^= num;
        }

        return {static_cast<int>(num1), static_cast<int>(num2)};
    }
};
}

