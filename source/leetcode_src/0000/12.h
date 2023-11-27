#pragma once

#include <unordered_map>
#include <string>
#include <array>

namespace leetcode_12
{

    class Solution
    {
    public:
        std::string intToRoman(int num)
        {
            return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
        }

    private:
        const std::array<std::string, 4> thousands{"", "M", "MM", "MMM"};
        const std::array<std::string, 10> hundreds{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        const std::array<std::string, 10> tens{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        const std::array<std::string, 10> ones{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    };
}
