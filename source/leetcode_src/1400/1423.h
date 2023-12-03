#pragma once
#include <vector>
#include <algorithm>

namespace leetcode_1423{
class Solution
{
public:
    int maxScore(const std::vector<int>& card_points, int k)
    {
        auto sum{ 0 };
        auto min_sum{ 0 };

        auto left{ 0 };
        auto right{ 0 };
        auto len{ card_points.size() - k };
        while (right < len)
            sum += card_points[right++];

        min_sum = sum;
        while (right < card_points.size())
        {
            sum += card_points[right++];
            sum -= card_points[left++];
            min_sum = std::min(min_sum, sum);
        }

        sum = 0;
        std::ranges::for_each(card_points, [&sum](const auto& v) { sum += v; });
        return sum - min_sum;
    }
};
}
