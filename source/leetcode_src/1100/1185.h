#pragma once

#include <string>
#include <vector>
#include <array>

namespace leetcode_1185 {
class Solution
{
public:
    std::string dayOfTheWeek(int day, int month, int year)
    {
        int days = 365 * (year - 1971) + (year - 1969) / 4;
        for (int i = 0; i < month - 1; ++i)
            days += _month_days[i];
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3)
            days += 1;
        days += day;
        return _week[(days + 3) % 7];
    }

private:
    static std::array<std::string, 7> _week;
    static std::array<int, 12> _month_days;
};

std::array<std::string, 7> Solution::_week = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday",
                                              "Sunday"};
std::array<int, 12> Solution::_month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
}