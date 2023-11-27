#pragma once

#include <vector>

namespace leetcode_2342
{
    class Solution
    {
    public:
        int maximumSum(std::vector<int>& nums)
        {
            auto max_digit_sum = std::vector<std::pair<int, int>>(100, std::make_pair(-1, -1));
            const auto n = nums.size();
            auto res = -1;
            for (const auto& num: nums)
            {
                auto sum = DigitSum(num);
                if (num > max_digit_sum[sum].first)
                {
                    max_digit_sum[sum].second = max_digit_sum[sum].first;
                    max_digit_sum[sum].first = num;
                }
                else if (num > max_digit_sum[sum].second)
                {
                    max_digit_sum[sum].second = num;
                }

                if (max_digit_sum[sum].first > -1 && max_digit_sum[sum].second > -1)
                    res = std::max(res, max_digit_sum[sum].first + max_digit_sum[sum].second);

            }
            return res;
        }

        static int DigitSum(int num)
        {
            auto sum = 0;
            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }
    };
}