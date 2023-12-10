#pragma once

#include <vector>

namespace leetcode_70 {
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < cache_.size())
            return cache_[n];

        for (auto i = cache_.size(); i <= n; ++i)
            cache_.push_back(cache_[i - 1] + cache_[i - 2]);

        return cache_[n];
    }

private:
    inline static std::vector<int> cache_{0, 1, 2};
};

}
