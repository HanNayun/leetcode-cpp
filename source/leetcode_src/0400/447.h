#pragma once

#include <vector>
#include <array>
#include <unordered_map>
#include <string>

namespace leetcode_447 {
class Solution
{
public:
    int numberOfBoomerangs(std::vector<std::vector<int>>& points)
    {
        int res{0};
        auto n{points.size()};
        for (const auto& p: points)
        {
            std::unordered_map<long, int> map;
            for (const auto& q: points)
            {
                auto dis{GetDistance({p[0], p[1]}, {q[0], q[1]})};
                ++map[dis];
            }

            for (const auto& [_, m]: map)
                res += m * (m - 1);
        }
        return res;

    }

    long GetDistance(std::array<int, 2> a, std::array<int, 2> b)
    {
        auto x{a[0] - b[0]};
        auto y{a[1] - b[1]};
        return x * x + y * y;
    }
};
}