#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode_1657{
class Solution
{
public:
    bool closeStrings(const std::string& word1, const std::string& word2)
    {
        auto mask1{ 0 };
        auto mask2{ 0 };

        auto freq1{ std::vector<int>(26, 0) };
        auto freq2{ std::vector<int>(26, 0) };

        std::ranges::for_each(word1.begin(), word1.end(), [&mask1, &freq1](const auto& ch)
        {
            auto idx{ ch - 'a' };
            mask1 |= 1 << idx;
            ++freq1[idx];
        });

        std::ranges::for_each(word2.begin(), word2.end(), [&mask2, &freq2](const auto& ch)
        {
            auto idx{ ch - 'a' };
            mask2 |= 1 << idx;
            ++freq2[idx];
        });

        if (mask1 != mask2)
            return false;

        std::ranges::sort(freq1, std::greater{});
        std::ranges::sort(freq2, std::greater{});
        for (int i = 0; i < 26; ++i)
        {
            if (freq1[i] != freq2[i])
                return false;

            if (freq1[i] == 0)
                break;
        }

        return true;
    }
};
}

