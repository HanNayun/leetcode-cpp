#pragma once

#include <vector>

namespace leetcode_1901 {
class Solution
{
public:
    std::vector<int> findPeakGrid(std::vector<std::vector<int>>& mat)
    {
        auto m{mat.size()};
        auto n{mat[0].size()};
        int low{0};
        int high{static_cast<int>(m) - 1};;
        while (low < high)
        {
            auto i{low + (high - low) / 2};
            auto it{std::max_element(mat[i].begin(), mat[i].end())};
            auto j{static_cast<int>(std::distance(mat[i].begin(), it))};
            if (i - 1 >= 0 && mat[i][j] < mat[i - 1][j])
                high = i - 1;
            else if (i + 1 < m && mat[i][j] < mat[i + 1][j])
                low = i + 1;
            else
                return std::vector<int>({i, j});
        }

        return {};
    }
};
}