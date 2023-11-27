#ifndef LEETCODE_CC_1572_H
#define LEETCODE_CC_1572_H

#include <vector>

namespace Leetcode_1572
{
    class Solution
    {
    public:
        int diagonalSum(std::vector<std::vector<int>>& mat)
        {
            auto res = 0;
            auto n = mat.size();
            for (int i = 0; i < n; i++)
            {
                res += mat[i][i];
                res += mat[i][n - 1 - i];
            }

            if (n % 2 == 1)
            {
                res -= mat[n / 2][n / 2];
            }

            return res;
        }
    };
}

#endif //LEETCODE_CC_1572_H
