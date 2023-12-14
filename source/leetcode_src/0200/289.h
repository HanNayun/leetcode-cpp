#pragma once

#include <vector>

namespace leetcode_289 {
class Solution
{
public:
    void gameOfLife(std::vector<std::vector<int>>& board)
    {
        auto m{board.size()};
        auto n{board[0].size()};
        auto copy_board{board};
        for (auto i = 0; i < m; ++i)
        {
            for (auto j = 0; j < n; ++j)
            {
                auto live_count{GetLiveNeighbors(board, i, j)};
                if (board[i][j] == 1 && live_count != 2 && live_count != 3)
                    copy_board[i][j] = 0;
                else if (board[i][j] == 0 && live_count == 3)
                    copy_board[i][j] = 1;
            }
        }

        board = copy_board;
    }

    static int GetLiveNeighbors(const std::vector<std::vector<int>>& board, int i, int j)
    {
        auto m{board.size()};
        auto n{board[0].size()};
        auto live_count{0};
        for (const auto& direction: directions)
        {
            auto x = i + direction.first;
            auto y = j + direction.second;
            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;
            if (board[x][y] == 1)
                ++live_count;
        }

        return live_count;
    }

private:
    static constexpr std::pair<int, int> directions[] = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0,  -1},
            {0,  1},
            {1,  -1},
            {1,  0},
            {1,  1}
    };
};
}
