#pragma once

#include <algorithm>

namespace Leetcode_2591 {

class Solution
{
public:
    int distMoney(int money, int children)
    {
        if (money < children)
            return -1;

        money -= children;
        auto count = std::min(money / 7, children);
        money -= count * 7;
        children -= count;

        if (children == 0 && money > 0 ||
            children == 1 && money == 3)
            count--;

        return count;
    }
};
}

