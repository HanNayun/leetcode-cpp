#pragma once

#include <vector>

namespace leetcode_2132 {
class Solution
{
public:
    bool possibleToStamp(std::vector<std::vector<int>>& grid, int stamp_height, int stamp_width)
    {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> sum(m + 2, std::vector<int>(n + 2, 0));
        std::vector<std::vector<int>> diff(m + 2, std::vector<int>(n + 2, 0));

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i - 1][j - 1];

        for (int i = 1; i + stamp_height - 1 <= m; ++i)
            for (int j = 1; j + stamp_width - 1 <= n; ++j)
            {
                int area_sum = sum[i + stamp_height - 1][j + stamp_width - 1]
                               - sum[i - 1][j + stamp_width - 1]
                               - sum[i + stamp_height - 1][j - 1]
                               + sum[i - 1][j - 1];

                if (area_sum != 0)continue;
                ++diff[i][j];
                --diff[i + stamp_height][j];
                --diff[i][j + stamp_width];
                ++diff[i + stamp_height][j + stamp_width];
            }

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
                if (diff[i][j] == 0 && grid[i - 1][j - 1] == 0)
                    return false;
            }
        }

        return true;
    }
};
}
