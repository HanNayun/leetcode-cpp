#pragma once

#include <vector>

namespace leetcode_2660 {
class Solution
{
public:

    int isWinner(std::vector<int>& player1, std::vector<int>& player2)
    {
        auto score1{CalculateScore(player1)};
        auto score2{CalculateScore(player2)};
        if (score1 > score2)
            return 1;
        else if (score1 < score2)
            return 2;
        else
            return 0;
    }

    int CalculateScore(std::vector<int> score_list)
    {
        int score_sum{0};
        int i{-2};
        int j{-1};
        for (int x = 0; x < score_list.size(); ++x)
        {
            auto score{score_list[x]};
            if (i >= 0 && score_list[i] == 10 ||
                j >= 0 && score_list[j] == 10)
            {
                score *= 2;
            }

            score_sum += score;
            ++i;
            ++j;
        }

        return score_sum;
    }
};
}