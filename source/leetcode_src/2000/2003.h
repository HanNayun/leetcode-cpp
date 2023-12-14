#pragma once

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <functional>

namespace Leetcode_2003 {
class Solution
{
public:
    std::vector<int> smallestMissingValueSubtree(std::vector<int>& parents, std::vector<int>& genes)
    {
        auto n{parents.size()};
        auto children{std::vector<std::vector<int>>(n)};
        std::for_each(parents.begin() + 1, parents.end(), [&](auto& parent)
        {
            children[parent].push_back(&parent - &parents[0]);
        });

        auto res{std::vector<int>(n, 1)};
        auto gene_set{std::vector<std::unordered_set<int>>(n)};

        std::function<int(int)> Dfs = [&](int node) -> int
        {
            gene_set[node].insert(genes[node]);
            std::for_each(children[node].begin(), children[node].end(), [&](auto child)
            {
                res[node] = std::max(res[node], Dfs(child));
                if (gene_set[node].size() < gene_set[child].size())
                    std::swap(gene_set[node], gene_set[child]);

                gene_set[node].merge(gene_set[child]);
            });

            while (gene_set[node].count(res[node]))
                ++res[node];

            return res[node];
        };

        Dfs(0);
        return res;
    }
};
}
