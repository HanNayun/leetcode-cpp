#pragma once

#include <vector>
#include <queue>
#include <array>

namespace leetcode_1631 {
class Solution
{
public:
    int minimumEffortPath(std::vector<std::vector<int>>& heights)
    {
        int left{0};
        int right{1000000};
        int res{0};
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            std::queue<std::pair<int, int>> path;
            path.emplace(0, 0);
            std::vector<std::vector<bool>> visited(heights.size(), std::vector<bool>(heights[0].size(), false));
            while (!path.empty())
            {
                auto [x, y] = path.front();
                path.pop();
                for (const auto& direction: directions_)
                {
                    int new_x = x + direction.first;
                    int new_y = y + direction.second;

                    if (new_x < 0 || new_x >= heights.size() || new_y < 0 || new_y >= heights[0].size())
                        continue;

                    if (visited[new_x][new_y] || std::abs(heights[new_x][new_y] - heights[x][y]) > mid)
                        continue;

                    visited[new_x][new_y] = true;
                    path.emplace(new_x, new_y);
                }
            }

            if (visited[heights.size() - 1][heights[0].size() - 1])
            {
                res = mid;
                right = mid - 1;
            } else
            {
                left = mid + 1;

            }
        }

        return res;
    }

private:
    static constexpr std::array<std::pair<int, int>, 4> directions_{{std::make_pair(0, 1),
                                                                     std::make_pair(0, -1),
                                                                     std::make_pair(1, 0),
                                                                     std::make_pair(-1, 0)}};
};
}