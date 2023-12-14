#pragma once


#include <vector>
#include <algorithm>
#include <numeric>

namespace leetcode_2300 {
class Solution
{
public:
    std::vector<int> successfulPairs(const std::vector<int>& spells, std::vector<int>& potions, long long success)
    {
        auto m{spells.size()};
        auto idx{std::vector<int>(m)};
        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&](auto a, auto b)
        {
            return spells[a] < spells[b];
        });

        std::sort(potions.begin(), potions.end(), [](auto a, auto b)
        {
            return a > b;
        });

        auto res{std::vector<int>(m)};
        auto n{potions.size()};
        auto pos{0};

        for (const auto& i: idx)
        {
            while (pos < n && 1l * spells[i] * potions[pos] >= success * 1l)
                ++pos;

            res[i] = pos;
        }

        return res;
    }
};
}

