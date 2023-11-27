#pragma once
#ifndef LEETCODE_715_H
#define LEETCODE_715_H

#include <algorithm>
#include <map>

namespace leetcode_715
{
    class RangeModule
    {
    public:
        void addRange(int left, int right)
        {
            auto it = ranges_.upper_bound(left);
            if (it != ranges_.begin())
            {
                const auto start = std::prev(it);
                if (start->second >= right)return;

                if (start->second >= left)
                {
                    left = start->first;
                    ranges_.erase(start);
                }
            }

            while (it != ranges_.end() && it->first <= right)
            {
                right = std::max(it->second, right);
                it = ranges_.erase(it);
            }

            ranges_[left] = right;
        }

        bool queryRange(int left, int right)
        {
            return std::any_of(ranges_.begin(), ranges_.end(), [&](const auto& range)
            {
                return left >= range.first && right <= range.second;
            });
        }

        void removeRange(int left, int right)
        {
            auto it = ranges_.upper_bound(left);
            if (it != ranges_.begin())
            {
                auto start = std::prev(it);
                if (start->second <= left) goto MergeRemain;

                auto ri = start->second;
                if (start->first == left)
                    ranges_.erase(start);
                else
                    start->second = left;

                if (ri > right)
                    ranges_[right] = ri;
            }

        MergeRemain:
            while (it != ranges_.end() && it->first < right)
            {
                if (it->second > right)
                {
                    ranges_[right] = it->second;
                    ranges_.erase(it);
                    break;
                }

                it = ranges_.erase(it);
            }
        }

    private:
        std::map<int, int> ranges_{};
    };
}
#endif //LEETCODE_715_H
