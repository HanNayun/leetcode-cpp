#ifndef LEETCODE_CC_2251_H
#define LEETCODE_CC_2251_H

#include <numeric>
#include <vector>
#include <map>
#include <algorithm>

namespace Leetcode_2251
{
    class Solution
    {
    public:
        std::vector<int> fullBloomFlowers(std::vector<std::vector<int>>& flowers, std::vector<int>& people)
        {
            auto bloom = std::map <int,int>{} ;

            for (auto flower: flowers)
            {
                bloom[flower[0]]++;
                bloom[flower[1] + 1]--;
            }

            auto idx = std::vector<int>(people.size());
            std::iota(idx.begin(), idx.end(), 0);
            std::sort(idx.begin(), idx.end(), [&](int a, int b)
            {
                return people[a] < people[b];
            });

            auto ans = std::vector<int>(people.size());
            auto cur = 0;
            auto now = bloom.begin();
            for (auto i: idx)
            {
                while (now != bloom.end() && now->first <= people[i])
                {
                    cur += now->second;
                    now++;
                }
                ans[i] = cur;
            }

            return ans;
        }
    };
}

#endif //LEETCODE_CC_2251_H