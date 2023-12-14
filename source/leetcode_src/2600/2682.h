#pragma once

#include "vector"

namespace Leetcode_2682 {
class Solution
{
public:
    std::vector<int> circularGameLosers(int n, int k)
    {
        auto players = std::vector<int>(n, 0);
        int time = 0;
        auto now = 0;

        while (true)
        {
            auto next = (now + time * k) % n;
            if (players[next] != 0)
                break;
            
            players[next]++;
            now = next;
            time++;
        }

        auto res = std::vector<int>{};
        for (int i = 0; i < n; i++)
            if (players[i] == 0)
                res.push_back(i + 1);

        return res;
    }
};
}

