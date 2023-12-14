#pragma once

#include <string>

namespace Leetcode_2264 {
class Solution
{
public:
    std::string largestGoodInteger(std::string num)
    {
        std::string res;
        auto n = num.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
            {
                res = std::max(res, num.substr(i, 3));
                i += 2;
            }
        }

        return res;
    }
};
}
