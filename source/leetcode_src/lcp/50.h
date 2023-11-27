#ifndef LEETCODE_50_H
#define LEETCODE_50_H

#include <vector>

namespace Leetcode_Lcp_50
{
    class Solution
    {
    public:
        int giveGem(std::vector<int>& gem, std::vector<std::vector<int>>& operations)
        {
            for (auto& op: operations)
            {
                int from{ op[0] };
                int to{ op[1] };
                auto num = gem[from] / 2;
                gem[to] += num;
                gem[from] -= num;
            }

            auto max = std::max_element(gem.begin(), gem.end());
            auto min = std::min_element(gem.begin(), gem.end());
            return *max - *min;
        }
    };
}
#endif //LEETCODE_50_H
