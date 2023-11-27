#ifndef LEETCODE_CC_1281_H
#define LEETCODE_CC_1281_H

namespace Leetcode_1281
{
    class Solution
    {
    public:
        int subtractProductAndSum(int n)
        {
            long sum = 0;
            long product = 1;
            while (n > 0)
            {
                auto last = n % 10;
                n /= 10;
                sum += last;
                product *= last;
            }
            return product - sum;
        }
    };
}

#endif //LEETCODE_CC_1281_H
