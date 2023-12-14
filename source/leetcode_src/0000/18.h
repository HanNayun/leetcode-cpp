#pragma once

#include <iterator>
#include <vector>
#include <algorithm>

namespace leetcode_18 {
class Solution
{
public:
    std::vector<std::vector<int>> fourSum(const std::vector<int>& nums, int target)
    {
        auto res = std::vector<std::vector<int>>{};
        auto n = static_cast<int>(nums.size());
        if (n < 4)
            return res;

        auto new_nums = std::vector<long>{};
        std::transform(nums.begin(), nums.end(), std::back_inserter(new_nums), [](int i)
        {
            return i;
        });
        std::sort(new_nums.begin(), new_nums.end());

        for (int i = 0; i <= n - 4; ++i)
        {
            if (i > 0 && new_nums[i] == new_nums[i - 1])
                continue;

            long long threshold = new_nums[i] + new_nums[i + 1] + new_nums[i + 2] + new_nums[i + 3];

            if (threshold > target)
                break;

            threshold = new_nums[i] + new_nums[n - 1] + new_nums[n - 2] + new_nums[n - 3];
            if (threshold < target)
                continue;

            for (int j = i + 1; j <= n - 3; ++j)
            {
                if (j > i + 1 && new_nums[j] == new_nums[j - 1])
                    continue;

                threshold = new_nums[i] + new_nums[j] + new_nums[j + 1] + new_nums[j + 2];
                if (threshold > target)
                    break;

                auto left = j + 1;
                auto right = n - 1;

                threshold = new_nums[i] + new_nums[j] + new_nums[right] + new_nums[right - 1];
                if (threshold < target)
                    continue;

                while (left < right)
                {
                    if (left > j + 1 && new_nums[left] == new_nums[left - 1])
                    {
                        ++left;
                        continue;
                    }

                    if (right < n - 1 && new_nums[right] == new_nums[right + 1])
                    {
                        --right;
                        continue;
                    }

                    long long sum = new_nums[i] + new_nums[j] + new_nums[left] + new_nums[right];
                    if (sum == target)
                    {
                        res.push_back(
                                {
                                        static_cast<int>(new_nums[i]),
                                        static_cast<int>(new_nums[j]),
                                        static_cast<int>(new_nums[left]),
                                        static_cast<int>(new_nums[right])
                                });
                        ++left;
                        --right;
                    }
                    else if (sum < target)
                    {
                        ++left;
                    }
                    else
                    {
                        --right;
                    }
                }
            }
        }

        return res;
    }
};
}
