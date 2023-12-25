#pragma once

#include <vector>

namespace leetcode_307 {
class NumArray
{
public:
    explicit NumArray(std::vector<int>& nums)
            : _nums(nums),
              _bit(std::vector<int>(nums.size() + 1))
    {
        for (int i = 1; i < _bit.size(); ++i)
        {
            _bit[i] += _nums[i - 1];
            auto j = i + LowBit(i);
            if (j < _bit.size())
                _bit[j] += _bit[i];
        }
    }

    void update(int index, int val)
    {
        Add(index + 1, val - _nums[index]);
        _nums[index] = val;
    }

    [[nodiscard]]
    int sumRange(int left, int right) const
    {
        return Query(right + 1) - Query(left);
    }

private:
    static int LowBit(int x)
    {
        return x & (-x);
    }

    void Add(int idx, int val)
    {
        while (idx < _bit.size())
        {
            _bit[idx] += val;
            idx += LowBit(idx);
        }
    }

    [[nodiscard]]
    int Query(int idx) const
    {
        int sum{0};
        while (idx > 0)
        {
            sum += _bit[idx];
            idx -= LowBit(idx);
        }
        return sum;
    }

    std::vector<int> _bit;
    std::vector<int> _nums;
};
}
