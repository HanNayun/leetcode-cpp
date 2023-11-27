#ifndef LEETCODE_421_H
#define LEETCODE_421_H

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iterator>
#include <algorithm>

namespace leetcode_421
{
    class Solution
    {
    public:
        constexpr static int kHighestDigit{ 31 };

        int findMaximumXOR(std::vector<int>& nums)
        {
            auto res{ 0 };
            auto bits{ std::unordered_set<int>{}};
            for (auto i = kHighestDigit; i >= 0; --i)
            {
                for (auto& num: nums) bits.insert(num >> i);
                auto next{ res * 2 + 1 };
                auto found =
                        std::find_if(bits.begin(), bits.end(), [&bits, &next](auto& bit) -> bool
                        {
                            return bits.count(bit ^ next);
                        }) != bits.end();

                if (found) res = next;
                else res <<= 1;
                bits.clear();
            }

            return res;
        }
    };
}
#endif //LEETCODE_421_H
