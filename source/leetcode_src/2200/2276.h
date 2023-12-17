#pragma once

#include <algorithm>
#include <map>

namespace leetcode_2276 {
class CountIntervals
{
public:
    void add(int left, int right)
    {
        auto interval{_intervals.upper_bound(right)};
        if (interval != _intervals.begin())
            interval--;

        while (interval != _intervals.end() &&
               interval->first <= right &&
               interval->second >= left)
        {
            int l = interval->first;
            int r = interval->second;
            left = std::min(left, l);
            right = std::max(right, r);
            _intervals.erase(interval);
            _count -= r - l + 1;

            interval = _intervals.upper_bound(right);
            if (interval != _intervals.begin())
                interval--;
        }

        _intervals[left] = right;
        _count += right - left + 1;
    }

    int count()
    {
        return _count;
    }

private:
    int _count = 0;
    std::map<int, int> _intervals;
};
}