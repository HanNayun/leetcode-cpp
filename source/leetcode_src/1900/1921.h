#ifndef LEETCODE_CC_1921_H
#define LEETCODE_CC_1921_H

#include <algorithm>
#include <vector>

namespace Leetcode_1921
{
    class Solution
    {
    public:
        int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed)
        {
            auto time = std::vector<double>();
            for (int i = 0; i < dist.size(); i++)
            {
                time.push_back(double(dist[i]) / speed[i]);
            }

            std::sort(time.begin(), time.end());

            int res = 0;
            int cost_time = 0;
            for (auto i: time)
            {
                if (cost_time >= i)
                {
                    break;
                }

                res++;
                cost_time++;
            }

            return res;

        }
    };
}

#endif //LEETCODE_CC_1921_H
