#pragma once
#include <functional>
#include <vector>

namespace leetcode_2646{
class Solution
{
public:
    int minimumTotalPrice(int n,
                          std::vector<std::vector<int>>& edges,
                          std::vector<int>& price,
                          std::vector<std::vector<int>>& trips)
    {
        std::vector<std::vector<int>> graph(n);
        for (const auto& edge: edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::vector<int> count(n, 0);
        std::function<bool(int, int, int)> calculate_count = [&graph, &count, &calculate_count
                ](int now, int parent, int end)-> bool
        {
            if (now == end)
            {
                ++count[now];
                return true;
            }

            for (const auto& child: graph[now])
            {
                if (child == parent)
                    continue;

                if (calculate_count(child, now, end))
                {
                    ++count[now];
                    return true;
                }
            }

            return false;
        };

        for (const auto& trip: trips)
            calculate_count(trip[0], -1, trip[1]);

        std::function<std::pair<int, int>(int, int)> calculate_dp = [&graph, &count, &price, &calculate_dp]
        (int now, int parent)
        {
            std::pair<int, int> res{ count[now] * price[now], count[now] * price[now] / 2 };
            for (const auto& child: graph[now])
            {
                if (child == parent)
                    continue;

                auto [x,y] = calculate_dp(child, now);
                res.first += std::min(x, y);
                res.second += x;
            }
            return res;
        };

        auto res{ calculate_dp(0, -1) };
        return std::min(res.first, res.second);
    }
};
}
