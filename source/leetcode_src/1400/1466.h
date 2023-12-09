#pragma once
#include <functional>
#include <unordered_map>
#include <vector>

namespace leetcode_1466{
class Solution
{
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections)
    {
        std::unordered_map<int, std::unordered_map<int, int>> graph;
        for (const auto& connection: connections)
        {
            graph[connection[0]][connection[1]] = 1;
            graph[connection[1]][connection[0]] = -1;
        }

        int res{ 0 };
        std::function<void(int, int)> dfs = [&graph, &dfs, &res](int now, int parent)
        {
            for (const auto& [next, direction]: graph[now])
            {
                if (next == parent)
                    continue;

                if (direction == 1)
                    ++res;

                dfs(next, now);
            }
        };

        dfs(0, -1);
        return res;
    }
};
}
