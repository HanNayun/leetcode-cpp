#pragma once

#include <vector>
#include <unordered_map>

namespace Leetcode_275 {
class Solution
{
public:
    int hIndex(std::vector<int>& citations)
    {
        auto n{int(citations.size())};
        if (n == 0)
            return 0;

        auto left{0};
        auto right{n - 1};
        while (left <= right)
        {
            auto middle{(left + right) / 2};
            if (n - middle <= citations[middle])
                right = middle - 1;
            else
                left = middle + 1;
        }

        return n - left;
    }
};
}

