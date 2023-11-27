#pragma once

#include <string>
#include <vector>
#include <numeric>

namespace leetcode_06
{
    class Solution
    {
    public:
        std::string convert(const std::string& s, int num_rows)
        {
            if (num_rows == 1) return s;

            auto rows{std::vector<std::string>(num_rows, "")};
            auto row{0};
            auto down{1};
            for (auto& i: s)
            {
                rows[row] += i;
                if (row == num_rows - 1)
                    down = -1;
                else if (row == 0)
                    down = 1;

                row += down;
            }

            return std::accumulate(rows.begin(), rows.end(), std::string{});
        }
    };
}
