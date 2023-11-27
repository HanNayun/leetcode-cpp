#pragma once

#include <numeric>
#include <vector>
#include <map>
#include <algorithm>

namespace leetcode_2736
{
    class Solution
    {
    public:
        std::vector<int> maximumSumQueries(std::vector<int>& nums1,
                                           std::vector<int>& nums2,
                                           std::vector<std::vector<int>>& queries)
        {
            auto sorted_nums = std::vector<std::pair<int, int>>{};
            auto n = nums1.size();
            for (int i = 0; i < n; ++i)
                sorted_nums.emplace_back(nums1[i], nums2[i]);
            std::sort(sorted_nums.begin(), sorted_nums.end(), std::greater<std::pair<int, int>>{});

            auto sorted_query = std::vector<std::tuple<int, int, int>>{};
            auto m = queries.size();
            for (int i = 0; i < m; ++i)
                sorted_query.emplace_back(i, queries[i][0], queries[i][1]);
            std::sort(sorted_query.begin(), sorted_query.end(), [](const auto& lhs, const auto& rhs)
            {
                return std::get<1>(lhs) > std::get<1>(rhs);
            });

            auto stack = std::vector<std::pair<int, int>>{};
            auto result = std::vector<int>(m, -1);
            auto j = 0;
            for (auto& [i, x, y]: sorted_query)
            {
                while (j < n && sorted_nums[j].first >= x)
                {
                    auto [num1, num2] = sorted_nums[j];
                    // because  nums[j][0] <= nums[j'][0],
                    // so if    nums[j][0] + nums[j][1] >= nums[j'][0] + nums[j'][1]
                    // must be  nums[j][1] >= nums[j'][1]
                    while (!stack.empty() && stack.back().second <= num1 + num2)
                        stack.pop_back();

                    if (stack.empty() || stack.back().first < num2)
                        stack.emplace_back(num2, num1 + num2);

                    ++j;
                }

                auto k = std::lower_bound(stack.begin(), stack.end(), std::make_pair(y, 0)) - stack.begin();
                if (k < stack.size())
                    result[i] = stack[k].second;
            }

            return result;
        }
    };
}
