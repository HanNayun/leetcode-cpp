#ifndef LEETCODE_137_H
#define LEETCODE_137_H

#include <vector>

namespace Leetcode_137
{
    class Solution
    {
    public:
        int singleNumber(std::vector<int>& nums)
        {

            int a{ 0 };
            int b{ 0 };
            for (int num: nums)
            {
                std::tie(a, b) = std::pair{ ~a & b & num | a & ~b & ~num, ~a & (b ^ num) };
            }
            return b;
        }
    };
}

#endif //LEETCODE_137_H
