#pragma once

#include <vector>
#include <algorithm>
#include <queue>

namespace leetcode_2127 {
class Solution
{
public:
    int maximumInvitations(std::vector<int>& favorite)
    {
        auto n{favorite.size()};
        auto in_degree{std::vector<int>(n, 0)};
        std::for_each(favorite.begin(), favorite.end(), [&in_degree](const auto& f)
        {
            ++in_degree[f];
        });

        auto leaf_nodes{std::queue<int>()};
        for (int i{0}; i < n; ++i)
            if (in_degree[i] == 0)
                leaf_nodes.push(i);

        auto visited{std::vector<int>(n, 0)};
        auto line_size{std::vector<int>(n, 1)};
        while (!leaf_nodes.empty())
        {// Travel the node not in the ring
            auto cur{leaf_nodes.front()};
            leaf_nodes.pop();
            visited[cur] = 1;
            auto v{favorite[cur]};
            line_size[v] = std::max(line_size[v], line_size[cur] + 1);
            --in_degree[v];
            if (in_degree[v] == 0) leaf_nodes.push(v);
        }

        auto ring{0};
        auto total{0};
        for (int i{0}; i < n; ++i)
        {
            if (visited[i]) continue;

            auto j{favorite[i]};
            if (favorite[j] == i)
            {// Two node rings can add the line nodes
                total += line_size[i] + line_size[j];
                visited[i] = visited[j] = 1;
            }
            else
            {// Multi node ring cannot add the line nodes
                auto u{i};
                auto cnt{0};
                while (true)
                {
                    ++cnt;
                    u = favorite[u];
                    visited[u] = 1;
                    if (u == i) break;
                }
                ring = std::max(ring, cnt);
            }
        }

        return std::max(total, ring);
    }
};
}
