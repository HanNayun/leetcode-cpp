#pragma once

#include <cmath>
#include <cstdlib>

namespace leetcode_07{
class Solution
{
public:
    int reverse(int x)
    {
        auto sign{ x > 0 ? 1 : -1 };
        x = std::abs(x);
        auto res{ 0l };
        while (x)
        {
            auto digit{ x % 10 };
            x /= 10;
            res *= 10;
            res += digit;
        }

        res *= sign;
        if (res <= INT32_MAX && res >= INT32_MIN)
            return res;
        return 0;
    }
};
}
