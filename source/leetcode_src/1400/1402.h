#ifndef LEETCODE_1402_H
#define LEETCODE_1402_H

#include <vector>
#include <algorithm>

namespace Leetcode_1402
{
    class Solution
    {
    public:
        int maxSatisfaction(std::vector<int>& satisfaction)
        {
            std::sort(satisfaction.begin(), satisfaction.end());
            int res{ 0 };
            int sum{ 0 };
            for (int i = int(satisfaction.size() - 1); i >= 0; --i)
            {
                auto after_select = res + satisfaction[i] + sum;
                if (after_select >= res)
                {
                    res = after_select;
                    sum += satisfaction[i];
                }
                else
                {
                    continue;
                }
            }

            return res;
        }
    };
}
#endif //LEETCODE_1402_H
