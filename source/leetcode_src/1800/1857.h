#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

namespace leetcode_1857
{

    class Solution
    {
    public:
        int largestPathValue(std::string colors, std::vector<std::vector<int>>& edges)
        {
            auto node_num = colors.size();
            auto in_degree = std::vector<int>(node_num, 0);
            auto graph = std::vector<std::vector<int>>(node_num, std::vector<int>());
            for (auto edge: edges)
            {
                graph[edge[0]].emplace_back(edge[1]);
                in_degree[edge[1]]++;
            }

            auto to_visit = std::queue<int>();
            for (auto i = 0; i < node_num; i++)
                if (in_degree[i] == 0)
                    to_visit.push(i);

            // Cycle detected
            if (to_visit.empty())
                return -1;

            auto visited = std::vector<bool>(node_num, false);
            auto dp = std::vector<std::vector<int>>{node_num, std::vector<int>(26, 0)};
            while (!to_visit.empty())
            {
                auto node = to_visit.front();

                // Cycle detected
                if (visited[node])
                    return -1;
                visited[node] = true;

                to_visit.pop();
                auto color = colors[node] - 'a';
                dp[node][color]++;
                for (auto next_node: graph[node])
                {
                    for (int i = 0; i < 26; i++)
                        dp[next_node][i] = std::max(dp[next_node][i], dp[node][i]);

                    // All parents visited
                    if (--in_degree[next_node] <= 0)
                        to_visit.push(next_node);
                }
            }

            auto has_unvisited_node = std::any_of(visited.begin(), visited.end(), [](const auto& v)
            { return !v; });

            if (has_unvisited_node)
                return -1;

            auto res = 0;
            for (auto nodes: dp)
                res = std::max(*std::max_element(nodes.begin(), nodes.end()), res);

            return res;
        }
    };
}

