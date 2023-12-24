#pragma once
namespace leetcode_1954 {
class Solution
{
public:
    long long minimumPerimeter(long long neededApples)
    {
        auto left{0};
        auto right{100000};
        auto area = [](long long n)
        {
            return 2 * n * (n + 1) * (2 * n + 1);
        };

        while (left < right)
        {
            auto mid = left + (right - left) / 2;
            if (area(mid) >= neededApples)
                right = mid;
            else
                left = mid + 1;
        }

        return left * 8;
    }
};
}