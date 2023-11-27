#ifndef LEETCODE_1559_H
#define LEETCODE_1559_H

#include <numeric>
#include <vector>
#include <unordered_map>

namespace Leetcode_1559
{
    class UnionFind
    {
    public:
        std::vector<int> parent_;
        std::vector<int> size_;
        int n_;
        int set_count_;

    public:
        explicit UnionFind(int n) : n_(n), set_count_(n), parent_(n), size_(n, 1)
        {
            std::iota(parent_.begin(), parent_.end(), 0);
        }

        int FindSet(int x)
        {
            int root = x;
            while (parent_[root] != root)
                root = parent_[root];

            int current = x;
            while (current != root)
            {
                int next = parent_[current];
                parent_[current] = root;
                current = next;
            }

            return root;
        }

        void Unite(int x, int y)
        {
            if (size_[x] < size_[y])
                std::swap(x, y);
            
            parent_[y] = x;
            size_[x] += size_[y];
            --set_count_;
        }

        // Return true if x and y are in different sets before uniting
        bool FindAndUnite(int x, int y)
        {
            int parent_x = FindSet(x);
            int parent_y = FindSet(y);
            if (parent_x != parent_y)
            {
                Unite(parent_x, parent_y);
                return true;
            }
            return false;
        }
    };

    class Solution
    {
    public:
        bool containsCycle(std::vector<std::vector<char>>& grid)
        {
            int m = static_cast<int>(grid.size());
            int n = static_cast<int>(grid[0].size());
            UnionFind uf(m * n);
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (i > 0 && grid[i][j] == grid[i - 1][j] && !uf.FindAndUnite(i * n + j, (i - 1) * n + j))
                        return true;

                    if (j > 0 && grid[i][j] == grid[i][j - 1] && !uf.FindAndUnite(i * n + j, i * n + j - 1))
                        return true;
                }
            }

            return false;
        }
    };

}
#endif //LEETCODE_1559_H
