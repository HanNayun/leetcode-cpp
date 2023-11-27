#pragma once

#include <string>
#include <vector>

namespace leetcode_17
{
    class Solution
    {
    public:
        std::vector<std::string> letterCombinations(const std::string& digits)
        {
            if (digits.empty()) return {};

            auto result{GenStringVec(digits[0] - '0')};
            auto len{digits.size()};
            for (int i = 1; i < len; ++i)
            {
                auto vec{GenStringVec(digits[i] - '0')};
                result = CombineStringVec(result, vec);
            }
            return result;
        }

        static std::vector<std::string>
        CombineStringVec(const std::vector<std::string>& v1, const std::vector<std::string>& v2)
        {
            auto result{std::vector<std::string>{}};
            for (const auto& s1: v1)
                for (const auto& s2: v2)
                    result.push_back(s1 + s2);
            return result;
        }

        static std::vector<std::string> GenStringVec(int digit)
        {
            auto res{std::vector<std::string>{}};
            auto str{kDigitToChar[digit]};
            for (int i = 0; i < 4; ++i)
            {
                if (str[i] == '\0') break;
                res.push_back(std::string{str[i]});
            }
            return res;
        }

    private:
        static constexpr char kDigitToChar[10][4] = {
                {'\0', '\0', '\0', '\0'},
                {'\0', '\0', '\0', '\0'},
                {'a',  'b',  'c',  '\0'},
                {'d',  'e',  'f',  '\0'},
                {'g',  'h',  'i',  '\0'},
                {'j',  'k',  'l',  '\0'},
                {'m',  'n',  'o',  '\0'},
                {'p',  'q',  'r',  's'},
                {'t',  'u',  'v',  '\0'},
                {'w',  'x',  'y',  'z'},
        };
    };
}
