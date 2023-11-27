#ifndef LEETCODE_CC_344_H
#define LEETCODE_CC_344_H

#include <vector>

namespace Leetcode_344
{
    class Solution
    {
    public:
        void reverseString(std::vector<char>& s)
        {
            auto left = 0;
            auto right = s.size() - 1;
            while (left < right)
            {
                auto temp = s[right];
                s[right] = s[left];
                s[left] = temp;
                left++;
                right--;
            }
        }
    };
}

#endif //LEETCODE_CC_344_H
