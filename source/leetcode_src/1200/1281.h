#pragma once
namespace Leetcode_1281 {
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

