#pragma once

#include <vector>
#include <algorithm>

namespace leetcode_765 {
class Solution
{
public:
    int minSwapsCouples(std::vector<int>& row)
    {
        auto res{0};
        auto len{row.size()};
        for (int i = 0; i < len; i += 2)
        {
            auto x{row[i] ^ 1};
            if (row[i + 1] == x)
                continue;
            
            ++res;
            std::swap(*std::find(row.begin() + i + 2, row.end(), x), row[i + 1]);
        }

        return res;

    }
};
}
