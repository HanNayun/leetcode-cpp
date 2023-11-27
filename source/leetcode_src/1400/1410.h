#pragma once

#include <string>
#include <map>

namespace leetcode_1410
{
    class Solution
    {
    public:
        std::string entityParser(const std::string& text)
        {
            auto start{-1};
            auto len{static_cast<int>(text.size())};
            auto res{std::string{}};
            auto end{0};
            while (end < len)
            {
                if (text[end] == '&')
                {
                    start = end;
                    while (end < len && text[end] != ';')++end;
                    if (end >= len)end = len - 1;
                    
                    auto entity = text.substr(start, end - start + 1);
                    if (entity_map_.find(entity) != entity_map_.end())
                    {
                        res += entity_map_.at(entity);
                        ++end;
                    }
                    else
                    {
                        res += text[start];
                        end = start + 1;
                    }
                }
                else
                {
                    res += text[end++];
                }
            }

            return res;
        }

    private:
        static const std::map<std::string, char> entity_map_;
    };

    const std::map<std::string, char> Solution::entity_map_{
            {"&quot;",  '\"'},
            {"&apos;",  '\''},
            {"&amp;",   '&'},
            {"&gt;",    '>'},
            {"&lt;",    '<'},
            {"&frasl;", '/'}
    };
}
