#pragma once
#ifndef LEETCODE_187_H
#define LEETCODE_187_H

#include <string>
#include <vector>
#include <unordered_map>

namespace leetcode_187
{
    class Solution
    {
    public:
        static constexpr int kSequenceLength{ 10 };
        std::unordered_map<char, int> char_to_int_{
                { 'A', 0 },
                { 'C', 1 },
                { 'G', 2 },
                { 'T', 3 }
        };

        std::vector<std::string> findRepeatedDnaSequences(std::string& s)
        {
            auto res{ std::vector<std::string>{}};
            if (s.size() < kSequenceLength) return res;
            auto now{ 0 };
            for (int i = 0; i < kSequenceLength - 1; ++i) now = (now << 2) | char_to_int_[s[i]];

            auto cnt{ std::unordered_map<int, int>{}};
            for (int i = 0; i <= s.size() - kSequenceLength; ++i)
            {
                now = ((now << 2) | char_to_int_[s[i + kSequenceLength - 1]]) & ((1 << kSequenceLength * 2) - 1);
                if (++cnt[now] == 2) res.push_back(s.substr(i, kSequenceLength));
            }
            return res;
        }
    };
}

#endif //LEETCODE_187_H
