#pragma once

#include <string>

namespace Leetcode_2525 {
class Solution
{
public:
    std::string categorizeBox(int length, int width, int height, int mass)
    {
        auto is_bulky{false};
        auto is_heavy{false};

        if (mass >= 100)
            is_heavy = true;

        if (length >= 1e4 || width >= 1e4 || height >= 1e4 ||
            double(long(length) * (width * height)) >= 1e9)
            is_bulky = true;

        if (is_bulky && is_heavy)
            return "Both";
        else if (is_bulky)
            return "Bulky";
        else if (is_heavy)
            return "Heavy";

        return "Neither";
    }
};
}
