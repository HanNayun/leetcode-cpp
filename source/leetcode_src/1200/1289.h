#pragma once

#include <vector>

namespace Leetcode_1289 {
class Solution
{
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid)
    {
        auto n = grid.size();
        auto min_sum = INT_MAX;
        auto second_min_sum = INT_MAX;
        auto min_index = 0;
        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] < min_sum)
            {
                second_min_sum = min_sum;
                min_sum = grid[0][j];
                min_index = j;
            }
            else if (grid[0][j] < second_min_sum)
            {
                second_min_sum = grid[0][j];
            }
        }

        for (int i = 1; i < n; i++)
        {
            auto temp_min_sum = INT_MAX;
            auto temp_second_min_sum = INT_MAX;
            auto temp_min_index = 0;

            for (int j = 0; j < n; j++)
            {
                auto temp = grid[i][j];
                if (j == min_index)
                {
                    temp += second_min_sum;
                }
                else
                {
                    temp += min_sum;
                }

                if (temp < temp_min_sum)
                {
                    temp_second_min_sum = temp_min_sum;
                    temp_min_sum = temp;
                    temp_min_index = j;
                }
            }

            min_sum = temp_min_sum;
            second_min_sum = temp_second_min_sum;
            min_index = temp_min_index;
        }

        return min_sum;
    }
};
}

