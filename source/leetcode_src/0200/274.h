#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>

namespace Leetcode_274 {
class Solution
{
public:
    int hIndex(std::vector<int>& citations)
    {
        if (citations.empty())
            return 0;

        auto n{*std::max_element(citations.begin(), citations.end())};

        auto times{std::unordered_map<int, int>{}};
        for (auto i: citations)
            ++times[i];

        auto sum{0};
        for (auto citation = n; citation > 0; --citation)
        {
            sum += times[citation];
            times[citation] = 0;
            if (sum >= citation)
                return citation;
        }

        return 0;
    }
};
}
