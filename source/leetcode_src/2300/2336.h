#pragma once

#include <set>

namespace leetcode_2336 {
class SmallestInfiniteSet
{
public:
    SmallestInfiniteSet()
    {

    }

    int popSmallest()
    {
        if (set_.empty())
            return minimum_++;
        
        auto it = set_.begin();
        int ret = *it;
        set_.erase(it);
        return ret;
    }

    void addBack(int num)
    {
        if (num < minimum_)
            set_.insert(num);
    }

private:
    int minimum_ = 1;
    std::set<int> set_;
};
}