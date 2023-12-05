#pragma once
#include <vector>

namespace leetcode_2477{
class Solution
{
public:
    long long minimumFuelCost(std::vector<std::vector<int>>& roads, int seats)
    {
        auto n{ roads.size() };
        std::vector<std::vector<int>> graph(n + 1);
        for (const auto& road: roads)
        {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        long long res{ 0 };
        Dfs(0, -1, seats, graph, res);
        return res;
    }

    static int Dfs(const int current,
                   const int parent,
                   const int seat,
                   const std::vector<std::vector<int>>& graph,
                   long long& res)
    {
        int people_sum{ 1 };
        for (const auto& child: graph[current])
        {
            if (child == parent)
                continue;

            int people_cnt = Dfs(child, current, seat, graph, res);
            people_sum += people_cnt;
            res += (people_cnt + seat - 1) / seat;
        }

        return people_sum;
    }
};
}
