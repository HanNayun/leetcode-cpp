#pragma once

#include <vector>
#include <string>
#include <algorithm>

namespace Leetcode_2731 {
class Solution
{
public:
    int sumDistance(std::vector<int>& nums, std::string s, int d)
    {
        constexpr int MOD{1000000007};
        auto num = nums.size();

        std::vector<long long> pos(num, 0);
        for (auto i = 0; i < num; ++i)
        {
            if (s[i] == 'L')
                pos[i] = nums[i] - d;
            else
                pos[i] = nums[i] + d;
        }

        std::sort(pos.begin(), pos.end());
        long long res{0};
        for (auto i = 1; i < num; ++i)
        {
            res += 1ll * (pos[i] - pos[i - 1]) * i % MOD * (num - i) % MOD;
            res %= MOD;
        }

        return res % MOD;
    }
};
}
