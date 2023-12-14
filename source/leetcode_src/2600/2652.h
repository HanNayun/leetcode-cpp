#pragma once

#include <vector>

namespace Leetcode_2652 {
class Solution
{
public:
    int sumOfMultiples(int n)
    {
        return F(n, 3) + F(n, 5) + F(n, 7)
               - F(n, 15) - F(n, 21) - F(n, 35)
               + F(n, 105);
    }

    int F(int n, int m)
    {
        return (m + n / m * m) * (n / m) / 2;
    }
};
}
