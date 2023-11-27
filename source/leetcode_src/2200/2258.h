#pragma once
#ifndef LEETCODE_2258_H
#define LEETCODE_2258_H

#include <vector>
#include <queue>
#include <algorithm>

namespace leetcode_2258
{
    enum class CellType
    {
        kGrass = 0,
        KFire = 1,
        kWall = 2,
    };

    constexpr auto operator+(CellType a) noexcept
    {
        return static_cast<std::underlying_type_t<CellType>>(a);
    }

    class Solution
    {
    public:
        static constexpr int kImpossible = -1;
        static constexpr int kAlwaysSafe = 1e9;
        static constexpr int kDirs[4][2] = {{ 0,  1 },
                                            { 0,  -1 },
                                            { 1,  0 },
                                            { -1, 0 }};

        int maximumMinutes(std::vector<std::vector<int>>& grid)
        {
            auto m{ static_cast<int>(grid.size()) };
            auto n{ static_cast<int>(grid[0].size()) };
            auto fire_time{ std::vector<std::vector<int>>(m, std::vector<int>(n, kAlwaysSafe)) };
            CalFireTime(grid, fire_time);

            auto res{ kImpossible };
            auto low{ 0 };
            auto high{ m * n };

            while (low <= high)
            {
                auto mid{ low + (high - low) / 2 };
                if (CanEscape(grid, fire_time, mid))
                {
                    res = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            return res >= m * n ? kAlwaysSafe : res;
        }

        static void CalFireTime(const std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& fire_time)
        {
            auto queue{ std::queue<std::pair<int, int>>{}};
            auto m{ grid.size() };
            auto n{ grid[0].size() };

            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    if (grid[i][j] == +CellType::KFire)
                    {
                        queue.emplace(i, j);
                        fire_time[i][j] = 0;
                    }

            auto time{ 1 };
            while (!queue.empty())
            {
                auto len{ queue.size() };
                for (int i = 0; i < len; ++i)
                {
                    auto cur{ queue.front() };
                    queue.pop();
                    for (auto& kDir: kDirs)
                    {
                        auto next{ std::pair<int, int>{ cur.first + kDir[0], cur.second + kDir[1] }};
                        if (next.first < 0 || next.first >= m || next.second < 0 || next.second >= n) continue;
                        if (grid[next.first][next.second] == +CellType::kWall) continue;
                        if (fire_time[next.first][next.second] != kAlwaysSafe) continue;

                        fire_time[next.first][next.second] = time;
                        queue.emplace(next);
                    }
                }
                ++time;
            }
        }

        static bool CanEscape(const std::vector<std::vector<int>>& grid,
                              const std::vector<std::vector<int>>& fire_time,
                              int time)
        {
            auto m{ grid.size() };
            auto n{ grid[0].size() };
            auto visit{ std::vector<std::vector<bool>>(m, std::vector<bool>(n, false)) };
            auto queue{ std::queue<std::tuple<int, int, long>>{}};

            queue.emplace(0, 0, time);
            visit[0][0] = true;

            while (!queue.empty())
            {
                auto [x, y, t]{ queue.front() };
                queue.pop();

                for (const auto& dir: kDirs)
                {
                    auto next_x{ x + dir[0] };
                    auto next_y{ y + dir[1] };

                    if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;
                    if (visit[next_x][next_y] || grid[next_x][next_y] == +CellType::kWall) continue;

                    if (next_x == m - 1 && next_y == n - 1)
                        return fire_time[next_x][next_y] >= t + 1;

                    if (fire_time[next_x][next_y] > t + 1)
                    {
                        visit[next_x][next_y] = true;
                        queue.emplace(next_x, next_y, t + 1);
                    }
                }
            }

            return false;
        }
    };
}
#endif //LEETCODE_2258_H
