#pragma once

#include <string>

namespace leetcode_504
{
    class Solution
    {
    public:
        std::string convertToBase7(int num)
        {

            auto flag{num < 0};
            if (flag)
                num = -num;

            auto res{std::string{}};
            while (num > 0)
            {
                res.insert(0, std::to_string(num % 7));
                num = num / 7;
            }

            if (flag)
                res = "-" + res;

            return res.empty() ? "0" : res;
        }
    };
}