#pragma once

#include <vector>
#include <algorithm>

namespace Leetcode_1465 {
class Solution
{
public:
    int maxArea(int h,
                int w,
                std::vector<int>& horizontal_cuts,
                std::vector<int>& vertical_cuts)
    {
        constexpr int MOD{static_cast<int>(1e9 + 7)};
        std::sort(horizontal_cuts.begin(), horizontal_cuts.end());
        std::sort(vertical_cuts.begin(), vertical_cuts.end());

        return CalculateMaxGap(horizontal_cuts, h) * CalculateMaxGap(vertical_cuts, w) % MOD;
    }

    static long CalculateMaxGap(const std::vector<int>& cuts, int max_len)
    {
        auto pre{0};
        auto max_gap{0};
        for (auto cut: cuts)
        {
            max_gap = std::max(max_gap, cut - pre);
            pre = cut;
        }
        return std::max(max_gap, max_len - pre);
    };
};
}

