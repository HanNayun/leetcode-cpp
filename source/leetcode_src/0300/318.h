#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace leetcode_318 {
class Solution
{
public:
    int maxProduct(std::vector<std::string>& words)
    {
        auto mask_map{std::unordered_map<int, unsigned long>{}};
        auto len{words.size()};
        for (const auto& word: words)
        {
            auto word_len{word.size()};
            auto mask{GenStringMask(word)};
            if (mask_map.find(mask) == mask_map.end())
                mask_map[mask] = word_len;
            else
                mask_map[mask] = std::max(mask_map[mask], word_len);
        }

        auto res{0ul};
        for (const auto& [mask, _]: mask_map)
            for (const auto& [mask2, _]: mask_map)
                if (!(mask & mask2))res = std::max(res, mask_map[mask] * mask_map[mask2]);

        return static_cast<int>(res);
    }

    static int GenStringMask(const std::string& str)
    {
        auto res{0};
        for (auto ch: str)res |= 1 << (ch - 'a');
        return res;
    }
};
}
