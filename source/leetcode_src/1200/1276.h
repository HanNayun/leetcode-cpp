#pragma once

#include <vector>

namespace leetcode_1276 {
class Solution
{
public:
    std::vector<int> numOfBurgers(int tomato_slices, int cheese_slices)
    {
        float a11 = 4, a12 = 2,
                a21 = 1, a22 = 1,
                b1 = tomato_slices, b2 = cheese_slices;

        if (a11 * a22 - a12 * a21 == 0)
            return {};

        float x = (b1 * a22 - b2 * a12) / (a11 * a22 - a12 * a21);
        float y = (b2 * a11 - b1 * a21) / (a11 * a22 - a12 * a21);

        if (x < 0 || y < 0 || x != static_cast<int>(x) || y != static_cast<int>(y))
            return {};

        return {(int) x, (int) y};
    }
};
}