#ifndef LEETCODE_136_H
#define LEETCODE_136_H

#include <vector>

namespace Leetcode_136
{
    class Solution
    {
    public:
        int singleNumber(std::vector<int>& nums)
        {
            int res{ 0 };
            for (auto& num: nums)
            {
                res ^= num;
            }

            return res;
        }
    };
}

#endif //LEETCODE_136_H
