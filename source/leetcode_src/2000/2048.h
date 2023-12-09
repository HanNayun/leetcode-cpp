#pragma once
#include <unordered_map>
#include <vector>
#include <__algorithm/ranges_find_if.h>

namespace leetcode_2048{
class Solution
{
public:
    int nextBeautifulNumber(int n)
    {
        for (int i = n + 1; i < 10000000; ++i)
            if (IsBeautiful(i))
                return i;

        return -1;
    }

private:
    static bool IsBeautiful(int n)
    {
        std::vector<int> counts(10, 0);
        while (n > 0)
        {
            counts[n % 10]++;
            n /= 10;
        }

        for (int i = 0; i < 10; ++i)
            if (counts[i] > 0 && counts[i] != i)
                return false;

        return true;
    }
};
}
