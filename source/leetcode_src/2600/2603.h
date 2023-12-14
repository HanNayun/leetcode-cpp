#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>

namespace Leetcode_2683 {
class Solution
{
private:
    struct Node
    {
    public:
        int Id;
        bool Has_Coin = false;
        std::set<int> Connected_Nodes;
        bool Deleted = false;

        [[nodiscard]]
        bool Is_Leaf() const
        {
            return Connected_Nodes.size() == 1;
        }
    };

    std::unordered_map<int, Node> _nodes;

public:
    int collectTheCoins(std::vector<int>& coins, std::vector<std::vector<int>>& edges)
    {
        _nodes = std::unordered_map<int, Node>();
        for (auto i = 0; i < coins.size(); i++)
        {
            _nodes[i] = Node();
            _nodes[i].Id = i;
            _nodes[i].Has_Coin = coins[i] == 1;
        }

        for (auto edge: edges)
        {
            _nodes[edge[0]].Connected_Nodes.emplace(edge[1]);
            _nodes[edge[1]].Connected_Nodes.emplace(edge[0]);
        }

        RemoveAllLeafWithoutCoin();
        RemoveLeafs();
        RemoveLeafs();

        return _nodes.empty()
               ? 0
               : 2 * (_nodes.size() - 1);
    }

private :
    void RemoveAllLeafWithoutCoin()
    {
        auto to_delete = std::queue<int>();
        std::for_each(_nodes.begin(), _nodes.end(), [&to_delete](auto& pair)
        {
            if (pair.second.Is_Leaf() && !pair.second.Has_Coin)
                to_delete.push(pair.second.Id);
        });

        while (!to_delete.empty())
        {
            auto& node = _nodes[to_delete.front()];
            auto& connected_node = _nodes[*node.Connected_Nodes.begin()];
            connected_node.Connected_Nodes.erase(node.Id);
            if (connected_node.Is_Leaf() && !connected_node.Has_Coin)
                to_delete.push(connected_node.Id);

            to_delete.pop();
            _nodes.erase(node.Id);
        }
    }

    void RemoveLeafs()
    {
        for (auto& node: _nodes)
            if (node.second.Is_Leaf())
                node.second.Deleted = true;

        for (auto node = _nodes.begin(); node != _nodes.end();)
        {
            if (node->second.Deleted)
            {
                for (auto connected_node: node->second.Connected_Nodes)
                    _nodes[connected_node].Connected_Nodes.erase(node->first);

                node = _nodes.erase(node);
            }
            else
            {
                node++;
            }
        }
    }
};
}

