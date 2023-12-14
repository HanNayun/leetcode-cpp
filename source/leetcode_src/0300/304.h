#pragma once

#include <vector>

namespace leeetcode_304 {
class NumMatrix
{
public:
    NumMatrix(std::vector<std::vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        sum_ = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                sum_[i][j] = matrix[i - 1][j - 1] + sum_[i][j - 1] + sum_[i - 1][j] - sum_[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sum_[row2 + 1][col2 + 1] - sum_[row1][col2 + 1] - sum_[row2 + 1][col1] + sum_[row1][col1];
    }

private:
    std::vector<std::vector<int>> sum_;
};
}
