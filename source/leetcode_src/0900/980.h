#pragma once

#include <vector>
#include <stack>
#include <string>
#include <iostream>

namespace Leetcode_980 {

class Solution
{
private:
    std::vector<std::vector<int>> _grid;
    int _reachable_point_num = 0;
    std::vector<int> _end_pos;
    int _res = 0;

public:
    int uniquePathsIII(std::vector<std::vector<int>>& grid)
    {
        auto m = grid.size();
        auto n = grid[0].size();
        _grid = grid;

        std::vector<int> start_pos;
        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (_grid[x][y] == 1)
                {
                    start_pos = {x, y};
                }
                else if (_grid[x][y] == 2)
                {
                    _end_pos = {x, y};
                }

                if (_grid[x][y] != -1)
                {
                    _reachable_point_num++;
                }
            }
        }

        dfs(start_pos[0], start_pos[1], 0);
        return _res;
    }

    void dfs(int x, int y, int visited_num)
    {
        visited_num++;
        auto v = _grid[x][y];
        _grid[x][y] = -1;
        if (visited_num == _reachable_point_num)
        {
            if (v == 2)
            {
                _res++;
            }
            _grid[x][y] = v;
            return;
        }

        for (auto next: std::vector<std::vector<int>>{{0,  1},
                                                      {0,  -1},
                                                      {1,  0},
                                                      {-1, 0}})
        {
            auto next_x = x + next[0];
            auto next_y = y + next[1];

            if (next_x < 0 || next_x >= _grid.size()
                || next_y < 0 || next_y >= _grid[0].size()
                || _grid[next_x][next_y] == -1)
            {
                continue;
            }

            dfs(next_x, next_y, visited_num);
        }

        _grid[x][y] = v;
    }
};
}

