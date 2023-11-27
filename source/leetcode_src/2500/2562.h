#ifndef LEETCODE_CC_2562_H
#define LEETCODE_CC_2562_H

#include <vector>
#include <string>

namespace Leetcode_2562
{
    class Solution
    {
    public:
        long long findTheArrayConcVal(std::vector<int>& nums)
        {
            int left{0};
            int right{int(nums.size() - 1)};
            long long sum{0};
            while (left <= right)
            {
                if (left < right)
                {
                    sum += std::stoll(std::to_string(nums[left]) + std::to_string(nums[right]));
                }
                else
                {
                    sum += nums[left];
                }
                left++;
                right--;
            }

            return sum;
        }
    };
}

#endif //LEETCODE_CC_2562_H
