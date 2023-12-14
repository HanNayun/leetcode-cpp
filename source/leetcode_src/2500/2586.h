#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

namespace leetcode_2586 {
class Solution
{
public:
    int vowelStrings(std::vector<std::string>& words, int left, int right)
    {
        return std::accumulate(words.begin() + left, words.begin() + right + 1, 0,
                               [&](int a, const std::string& b)
                               {
                                   return a + static_cast<int>(IsVowelWork(b));
                               });
    }

    static bool IsVowelWork(const std::string& word)
    {
        static constexpr unsigned int kVowelMask{
                1 << ('a' - 'a') | 1 << ('e' - 'a') | 1 << ('i' - 'a') | 1 << ('o' - 'a') | 1 << ('u' - 'a')};

        auto first_char{1 << (word[0] - 'a')};
        auto last_char{1 << (word[word.size() - 1] - 'a')};
        return (first_char & kVowelMask) && (last_char & kVowelMask);
    }
};
}
