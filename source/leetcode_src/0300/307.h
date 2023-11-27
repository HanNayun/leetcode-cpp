#pragma once
#ifndef LEETCODE_307_H
#define LEETCODE_307_H

#include <vector>

namespace leetcode_307
{
    class NumArray
    {
    public:
        NumArray(std::vector<int>& nums)
                : nums_(nums),
                  tree_(std::vector<int>(nums.size() + 1))
        {
            for (int i = 0; i < nums.size(); ++i)
                Add(i + 1, nums[i]);
        }

        void update(int index, int val)
        {
            Add(index + 1, val - nums_[index]);
            nums_[index] = val;
        }

        int sumRange(int left, int right) const
        {
            return Query(right + 1) - Query(left);
        }

    private:
        std::vector<int>& nums_;
        std::vector<int> tree_;

        static int LowBit(int x)
        {
            return x & (-x);
        }

        void Add(int idx, int val)
        {
            while (idx < tree_.size())
            {
                tree_[idx] += val;
                idx += LowBit(idx);
            }
        }

        [[nodiscard]]
        int Query(int idx) const
        {
            int sum{0};
            while (idx > 0)
            {
                sum += tree_[idx];
                idx -= LowBit(idx);
            }
            return sum;
        }
    };
}
#endif //LEETCODE_307_H
