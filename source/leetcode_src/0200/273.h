#pragma once

#include <string>

namespace leetcode_273 {
class Solution
{
public:
    std::string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        auto sb{std::string{}};
        for (int i = 3, unit = 1000000000; i >= 0; i--, unit /= 1000)
        {
            int curNum = num / unit;
            if (curNum != 0)
            {
                num -= curNum * unit;
                auto curr{std::string{}};
                Recursion(curr, curNum);
                curr.append(thousands_[i]).append(" ");
                sb.append(curr);
            }
        }
        while (sb.back() == ' ')
            sb.pop_back();

        return sb;
    }

    void Recursion(std::string& curr, int num)
    {
        if (num == 0)
            return;
        else if (num < 10)
            curr = curr + singles_[num] + " ";
        else if (num < 20)
            curr = curr + teens_[num - 10] + " ";
        else if (num < 100)
        {
            curr = curr + tens_[num / 10] + " ";
            Recursion(curr, num % 10);
        }
        else
        {
            curr = curr + singles_[num / 100] + " Hundred ";
            Recursion(curr, num % 100);
        }
    }

private:
    static constexpr const char* singles_[]{"", "One", "Two", "Three", "Four",
                                            "Five", "Six", "Seven", "Eight", "Nine"};
    static constexpr const char* teens_[]{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                                          "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    static constexpr const char* tens_[]{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty",
                                         "Sixty", "Seventy", "Eighty", "Ninety"};
    static constexpr const char* thousands_[]{"", "Thousand", "Million", "Billion"};
};
}