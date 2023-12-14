#pragma once


#include <string>
#include <string_view>

namespace leetcode_2609 {
class Solution
{
public:
    int findTheLongestBalancedSubstring(std::string_view sv)
    {
        auto sv_len{sv.size()};
        auto res{0};
        auto count_0{0};
        auto count_1{0};
        for (int i = 0; i < sv_len; ++i)
        {
            if (sv[i] == '1')
            {
                ++count_1;
                res = std::max(res, std::min(count_0, count_1));
            }
            else if (i == 0 || sv[i - 1] == '1')
            {
                count_0 = 1;
                count_1 = 0;
            }
            else
            {
                ++count_0;
            }
        }

        return res << 1;
    }
};
}
