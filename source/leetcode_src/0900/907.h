#pragma once

#include <vector>
#include <numeric>

namespace leetcode_907
{
    class Solution
    {
    public:
        int sumSubarrayMins(std::vector<int>& arr)
        {
            static constexpr auto MOD = 1000000007;
            auto n{arr.size()};
            auto right_min{std::vector<int>(n)};
            auto left_min{std::vector<int>(n)};
            std::iota(right_min.begin(), right_min.end(), 0);
            std::iota(left_min.begin(), left_min.end(), 0);

            for (int i = 0; i < n; ++i)
            {
                auto pre{i - 1};
                auto now{arr[i]};
                while (pre >= 0 && now < arr[pre])
                {
                    left_min[i] = left_min[pre];
                    if (pre == left_min[pre])
                        --pre;
                    else
                        pre = left_min[pre];
                }
            }

            for (int i = static_cast<int>(n) - 1; i >= 0; --i)
            {
                auto pre{i + 1};
                auto now{arr[i]};
                while (pre < n && now <= arr[pre])
                {
                    right_min[i] = right_min[pre];
                    if (pre == right_min[pre])
                        ++pre;
                    else
                        pre = right_min[pre];
                }
            }

            auto res{0l};
            for (int i = 0; i < n; ++i)
            {
                res += static_cast<long>(right_min[i] - i + 1) * (i - left_min[i] + 1) * arr[i];
                res %= MOD;
            }

            return static_cast<int>(res);
        }
    };
}