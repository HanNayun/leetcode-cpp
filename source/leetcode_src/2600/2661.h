#pragma once
#include <unordered_map>
#include <vector>

namespace leetcode_2661{
class Solution
{
public:
    int firstCompleteIndex(std::vector<int>& arr,
                           std::vector<std::vector<int>>& mat)
    {
        auto row_map{ std::unordered_map<int, int>{} };
        auto col_map{ std::unordered_map<int, int>{} };
        auto coordinate_map{ std::unordered_map<int, std::pair<int, int>>{} };

        const auto m = mat.size();
        const auto n = mat[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                coordinate_map[mat[i][j]] = { i, j };

        for (int i = 0; i < arr.size(); ++i)
        {
            const auto& [x, y] = coordinate_map[arr[i]];
            if (++row_map[y] >= m || ++col_map[x] >= n)
                return i;
        }

        return static_cast<int>(arr.size());
    }
};
}
