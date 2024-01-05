#pragma once

#include <algorithm>
#include <vector>
#include <stack>

namespace leetcode_1944 {
class Solution
{
public:
    std::vector<int> canSeePersonsCount(std::vector<int>& heights)
    {
        int n{static_cast<int>(heights.size())};
        std::stack<int> right_people;
        std::vector<int> res(n, 0);

        for (int i = n - 1; i >= 0; --i)
        {
            auto m{0};
            while (!right_people.empty() && right_people.top() < heights[i])
            {
                right_people.pop();
                ++m;
            }

            if (!right_people.empty())
                ++m;

            res[i] = m;
            right_people.push(heights[i]);
        }

        return res;
    }
};
}