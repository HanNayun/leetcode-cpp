#ifndef LEETCODE_CC_2582_H
#define LEETCODE_CC_2582_H

namespace Leetcode_2582
{

    class Solution
    {
    public:
        int passThePillow(int n, int time)
        {
            auto turns = time / (n - 1);
            auto left_time = time % (n - 1);
            if (turns % 2 == 0)
            {
                return left_time + 1;
            }
            else
            {
                return n - left_time;
            }
        }
    };
}

#endif //LEETCODE_CC_2582_H
