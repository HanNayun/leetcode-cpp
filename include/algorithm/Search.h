#pragma once

#include <vector>

namespace leetcode_algorithm {
class Search
{
public:
    template<class T>
    static std::vector<T>::iterator BinarySearch(std::vector<T>& list, T target)
    {
        auto start{list.begin()};
        auto end{list.end() - 1};
        if (target < *start || target > *end)
            return list.end();

        while (start < end)
        {
            auto mid = start + (end - start) / 2;
            if (*mid < target)
                start = mid + 1;
            else
                end = mid;
        }

        return *start == target ? start : list.end();
    }
};

} // leetcode_algorithm

