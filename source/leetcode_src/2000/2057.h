#ifndef LEETCODE_CC_2057_H
#define LEETCODE_CC_2057_H

#include <vector>

namespace leetcode_2057
{
    using std::vector;

    class Solution
    {
    public:
        int smallestEqual(vector<int>& nums)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (i % 10 == nums[i])
                {
                    return i;
                }
            }

            return -1;
        }
    };
}
#endif //LEETCODE_CC_2057_H
