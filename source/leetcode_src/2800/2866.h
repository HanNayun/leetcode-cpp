#pragma once

#include <vector>
#include <stack>

namespace leetcode_2866 {
class Solution
{
public:
    long long maximumSumOfHeights(std::vector<int>& max_heights)
    {
        int n{static_cast<int>(max_heights.size())};

        std::vector<long long> prefix(n, 0);
        std::stack<int> st1;
        for (int i = 0; i < n; ++i)
        {
            while (!st1.empty() && max_heights[st1.top()] > max_heights[i])
                st1.pop();

            if (st1.empty())
                prefix[i] = static_cast<long long>((i + 1)) * max_heights[i];
            else
                prefix[i] = prefix[st1.top()] + static_cast<long long>(i - st1.top()) * max_heights[i];

            st1.emplace(i);
        }

        std::vector<long long> suffix(n, 0);
        std::stack<int> st2;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st2.empty() && max_heights[st2.top()] > max_heights[i])
                st2.pop();

            if (st2.empty())
                suffix[i] = static_cast<long long>(n - i) * max_heights[i];
            else
                suffix[i] = suffix[st2.top()] + static_cast<long long>(st2.top() - i) * max_heights[i];

            st2.emplace(i);
        }

        long long res{0};
        for (int i = 0; i < n; ++i)
            res = std::max(res, prefix[i] + suffix[i] - max_heights[i]);

        return res;
    }
};
}
