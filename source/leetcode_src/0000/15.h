#pragma once

#include <vector>
#include <algorithm>

namespace leetcode_15{
class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        auto res{ std::vector<std::vector<int>>{} };
        auto len{ nums.size() };
        for (int i = 0; i < len; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            auto j{ i + 1 };
            auto k = len - 1;
            auto target{ -nums[i] };
            while (j < k)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    ++j;
                    continue;
                }

                auto sum{ nums[j] + nums[k] };
                if (sum == target) res.push_back({ nums[i], nums[j++], nums[k] });
                else if (sum < target)++j;
                else --k;
            }
        }

        return res;
    }
};
}
