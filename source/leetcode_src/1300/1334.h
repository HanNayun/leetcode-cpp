#pragma once
#ifndef INC_1334_H
#define INC_1334_H

#include <vector>

namespace leetcode_1334
{
    class Solution
    {
    public:
        int findTheCity(const int n, const std::vector<std::vector<int>>& edges, const int distance_threshold)
        {
            long long graph[n][n];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    graph[i][j] = INT_MAX;

            for (const auto& edge: edges)
                graph[edge[0]][edge[1]] = graph[edge[1]][edge[0]] = edge[2];

            long long min_distance[n][n];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    min_distance[i][j] = i == j ? 0 : graph[i][j];

            for (int k = 0; k < n; ++k)
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        min_distance[i][j] = std::min(min_distance[i][j], min_distance[i][k] + min_distance[k][j]);

            auto min_connected_cities = INT_MAX;
            auto city = 0;
            for (int i = 0; i < n; ++i)
            {
                auto cities = 0;
                for (int j = 0; j < n; ++j)
                    if (min_distance[i][j] <= distance_threshold)
                        ++cities;

                if (cities <= min_connected_cities)
                {
                    min_connected_cities = cities;
                    city = i;
                }
            }

            return city;
        }
    };
}

#endif //INC_1334_H

