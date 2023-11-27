#ifndef LEETCODE_CC_833_H
#define LEETCODE_CC_833_H

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

namespace Leetcode_833
{
    class Solution
    {
    public:
        std::string findReplaceString(std::string s, std::vector<int>& indices, std::vector<std::string>& sources,
                                      std::vector<std::string>& targets)
        {
            auto k = indices.size();

            auto ops = std::vector<int>(k);
            std::iota(ops.begin(), ops.end(), 0);
            std::sort(ops.begin(), ops.end(), [&indices](int i, int j)
            { return indices[i] < indices[j]; });

            auto n = s.size();
            std::string res;
            int pos = 0;
            for (int i = 0; i < n;)
            {
                // if the now operation's start position is before the current position, skip to next operation
                while (pos < k && indices[ops[pos]] < i)
                {
                    pos++;
                }

                auto is_match = false;
                // when now operation's start position is the current position, check if the source string matches
                while (pos < k && indices[ops[pos]] == i)
                {
                    auto str = s.substr(i, sources[ops[pos]].size());
                    if (str == sources[ops[pos]])
                    {
                        is_match = true;
                        break;
                    }
                    pos++;
                }

                if (is_match)
                {
                    res += targets[ops[pos]];
                    i += int(sources[ops[pos]].size());
                }
                else
                {
                    res += s[i];
                    i++;
                }
            }

            return res;
        }
    };
}

#endif //LEETCODE_CC_833_H
