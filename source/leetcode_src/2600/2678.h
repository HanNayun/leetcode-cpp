#pragma once

#include <vector>
#include <string>

namespace Leetcode_2678 {
class Solution
{
public:
    int countSeniors(std::vector<std::string>& details)
    {
        int res{0};
        constexpr auto senior_age{60};
        for (const auto& detail: details)
        {
            auto age = std::stoi(detail.substr(11, 2));
            if (age > senior_age)
                res++;
        }

        return res;
    }
};
}
