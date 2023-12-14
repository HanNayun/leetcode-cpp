#pragma once

#include <unordered_set>
#include <string>

namespace Leetcode_2698 {
class Solution
{
    struct Help
    {
        int arr_[1001]{};

        consteval Help()
        {
            auto sum{0};
            for (int i = 1; i < 1001; ++i)
            {
                auto square{i * i};
                if (IsPunishmentNumber(square, i))
                    sum += square;

                arr_[i] = sum;
            }
        }

        consteval bool IsPunishmentNumber(int num, int sum)
        {
            if (num == sum)
                return true;
            int base{10};
            while (base < num)
            {
                if (IsPunishmentNumber(num / base, sum - num % base)) return true;
                base *= 10;
            }

            return false;
        }
    };

public:
    int punishmentNumber(int n)
    {
        constexpr Help help;
        return help.arr_[n];
    }
};
}

