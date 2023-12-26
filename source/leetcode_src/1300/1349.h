#pragma once

#include <functional>
#include <vector>
#include <unordered_map>

namespace leetcode_1349 {
class Solution
{
public:
    static int GetBitCount(int i)
    {
        int count = 0;
        while (i)
        {
            count++;
            i &= (i - 1);
        }
        return count;
    }

    int maxStudents(std::vector<std::vector<char>>& seats)
    {
        auto m{seats.size()};
        auto n{seats[0].size()};
        std::unordered_map<int, int> memory;

        auto IsSameLineCompliant = [&n, &seats](int row, int state)
        {
            for (int i = 0; i < n; ++i)
            {
                auto has_student_sit = state & (1 << i);
                if (!has_student_sit)
                    continue;

                if (seats[row][i] == '#')
                    return false;

                if (i > 0 && (state & (1 << (i - 1))))
                    return false;
            }

            return true;
        };

        auto IsCrossLineCompliant = [&n, &seats](int row, int state, int other_state)
        {
            for (int i = 0; i < n; ++i)
            {
                auto is_student_sit = state & (1 << i);
                if (!is_student_sit)
                    continue;

                if (i > 0 && (other_state & (1 << (i - 1))))
                    return false;

                if (i < n - 1 && (other_state & (1 << (i + 1))))
                    return false;
            }

            return true;
        };

        std::function<int(int, int)> dp = [&](int row, int state)
        {
            auto key = (row << n) | state;
            if (memory.find(key) != memory.end())
                return memory[key];


            if (!IsSameLineCompliant(row, state))
            {
                memory[key] = INT_MIN;
                return INT_MIN;
            }

            auto student_count = GetBitCount(state);
            if (row == 0)
            {
                memory[key] = student_count;
                return memory[key];
            }

            auto max = 0;

            for (int next_row_state = 0; next_row_state < (1 << n); ++next_row_state)
            {
                if (!IsCrossLineCompliant(row, state, next_row_state))
                    continue;

                max = std::max(max, dp(row - 1, next_row_state));
            }

            memory[key] = max + student_count;
            return memory[key];
        };

        auto max{0};
        for (int i = 0; i < (1 << n); ++i)
            max = std::max(max, dp(m - 1, i));

        return max;
    }
};
}