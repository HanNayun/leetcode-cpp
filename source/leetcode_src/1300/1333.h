#ifndef LEETCODE_CC_1333_H
#define LEETCODE_CC_1333_H

#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

namespace Leetcode_1333
{
    class Solution
    {
    public:
        std::vector<int>
        filterRestaurants(std::vector<std::vector<int>>& restaurants, int vegan_friendly, int max_price,
                          int max_distance)
        {
            std::vector<int> ans;
            auto end = partition(restaurants.begin(), restaurants.end(), [&](auto& v)
            { return (!vegan_friendly || v[2]) && v[3] <= max_price && v[4] <= max_distance; });

            std::sort(restaurants.begin(), end, [](auto& a, auto& b)
            { return std::pair{ a[1], a[0] } > std::pair{ b[1], b[0] }; });

            std::transform(restaurants.begin(), end, std::back_inserter(ans), [](auto& v)
            { return v[0]; });

            return ans;
        }
    };
}

#endif //LEETCODE_CC_1333_H
