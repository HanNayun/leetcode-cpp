#ifndef LEETCODE_CC_605_H
#define LEETCODE_CC_605_H

#include "vector"

namespace Leetcode_605
{
    class Solution
    {
    public:
        bool canPlaceFlowers(std::vector<int>& flowerbed, int n)
        {
            auto count = 0;
            auto len = flowerbed.size();
            for (int i = 0; i < len; i++)
            {
                if (flowerbed[i] == 0 &&
                    (i == 0 || flowerbed[i - 1] == 0) &&
                    (i == len - 1 || flowerbed[i + 1] == 0))
                {
                    count++;
                    i++;
                }
            }

            return count >= n;
        }
    };
}

#endif //LEETCODE_CC_605_H
