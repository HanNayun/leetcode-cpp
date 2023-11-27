#ifndef LEETCODE_2103_H
#define LEETCODE_2103_H

#include <string>
#include <algorithm>
#include <vector>

namespace leetcode_2103
{
    class Solution
    {
    public:
        static constexpr int kPoleNum{ 10 };

        int countPoints(std::string rings)
        {
            auto state{ std::vector<int>(kPoleNum, 0) };
            for (int i = 0; i < rings.size(); i += 2)
            {
                auto color{ rings[i] };
                auto pos{ rings[i + 1] - '0' };

                if (color == 'R') state[pos] |= 1;
                else if (color == 'G') state[pos] |= 2;
                else if (color == 'B') state[pos] |= 4;
            }

            auto result{ 0 };
            for (const auto& s: state)
                if (s == 7) ++result;

            return result;
        }
    };
}
#endif //LEETCODE_2103_H
