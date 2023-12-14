#pragma once

namespace Leetcode_2520 {
class Solution
{
public:
    int countDigits(int num)
    {
        auto res{0};
        auto base{num};
        while (base)
        {
            if (num % (base % 10) == 0)
                ++res;

            base /= 10;
        }

        return res;
    }
};
}
