#ifndef LEETCODE_CC_215_H
#define LEETCODE_CC_215_H

#include <random>
#include <vector>

namespace Leetcode_215
{
    class Solution
    {
    public:
        std::vector<int> Nums;

        int findKthLargest(std::vector<int>& nums, int k)
        {
            Nums = nums;
            return QuickSelect(0, nums.size() - 1, nums.size() - k);
        }

        int QuickSelect(int left, int right, int target_index)
        {
            auto index = RandomPartition(left, right);
            if (index == target_index)
            {
                return Nums[index];
            }
            else
            {
                return index < target_index
                       ? QuickSelect(index + 1, right, target_index)
                       : QuickSelect(left, index - 1, target_index);
            }
        }

        int RandomPartition(int left, int right)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dist(left, right); // Range [1, 100]
            int random_number = dist(gen);

            std::swap(Nums[random_number], Nums[right]);
            return Partition(left, right);
        }

        int Partition(int left, int right)
        {
            auto pivot = Nums[right];
            auto sorted_index = left - 1;

            for (auto i = left; i < right; i++)
            {
                if (Nums[i] < pivot)
                {
                    std::swap(Nums[++sorted_index], Nums[i]);
                }
            }

            std::swap(Nums[++sorted_index], Nums[right]);
            return sorted_index;
        }
    };
}

#endif //LEETCODE_CC_215_H
