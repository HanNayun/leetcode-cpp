#pragma once

#include <vector>

namespace leetcode_04 {
class Solution
{
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        auto m{static_cast<int>(nums1.size())};
        auto n{static_cast<int>(nums2.size())};

        if (m + n == 0)
            return 0;

        if ((m + n) % 2)
            return FindKthNumber(nums1, nums2, (m + n + 1) / 2);

        return (FindKthNumber(nums1, nums2, (m + n + 1) / 2)
                + FindKthNumber(nums1, nums2, (m + n + 2) / 2)) / 2.0;
    }

    static int FindKthNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k)
    {
        auto m{static_cast<int>(nums1.size())};
        auto n{static_cast<int>(nums2.size())};

        int i{0};
        int j{0};

        while (k > 1)
        {
            if (i == m || j == n) break;

            auto i1 = std::min(m - 1, k / 2 + i - 1);
            auto j1 = std::min(n - 1, k / 2 + j - 1);

            if (nums1[i1] <= nums2[j1])
            {
                k -= i1 + 1 - i;
                i = i1 + 1;
                continue;
            }

            if (nums1[i1] > nums2[j1])
            {
                k -= j1 + 1 - j;
                j = j1 + 1;
                continue;
            }
        }

        if (i == m) return nums2[j + k - 1];
        if (j == n) return nums1[i + k - 1];
        return std::min(nums1[i], nums2[j]);
    }
};
}
