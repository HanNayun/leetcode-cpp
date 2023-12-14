#pragma once

#include <vector>
#include <algorithm>

namespace Leetcode_Lcp_06 {
class Solution
{
public:
    int minCount(std::vector<int>& coins)
    {
        auto count = 0;
        std::for_each(coins.begin(), coins.end(), [&count](auto coin)
        { count += (coin + 1) / 2; });

        return count;
    }
};
}

