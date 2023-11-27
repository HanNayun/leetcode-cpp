//
// Created by HanNayun on 2023/10/2.
//

#ifndef LEETCODE_CC_06_H
#define LEETCODE_CC_06_H

#include <vector>
#include <algorithm>

namespace Leetcode_Lcp_06
{
    class Solution
    {
    public:
        int minCount(std::vector<int>& coins)
        {
            auto count = 0;
            std::for_each(coins.begin(), coins.end(), [&count](auto coin)
            { count += (coin + 1) / 2; });

            return count;
        }
    };
}

#endif //LEETCODE_CC_06_H
