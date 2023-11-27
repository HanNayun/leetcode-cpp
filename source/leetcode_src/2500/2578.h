#ifndef LEETCODE_CC_2578_H
#define LEETCODE_CC_2578_H

#include <vector>
#include <algorithm>
#include <string>

namespace Leetcode_2578
{
    class Solution
    {
    public:
        int splitNum(int num)
        {
            std::string str = std::to_string(num);
            std::sort(str.begin(), str.end());
            int a = 0;
            int b = 0;
            for (int i = 0; i < str.size(); ++i)
            {
                if (i % 2 == 0)
                {
                    a = a * 10 + str[i] - '0';
                }
                else
                {
                    b = b * 10 + str[i] - '0';
                }
            }

            return a + b;
        }
    };
}
#endif //LEETCODE_CC_2578_H
