#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <array>

namespace leetcode_2707 {
class Trie
{
private:
    std::array<Trie*, 26> _children{};
    bool _is_end;

public:
    static bool Track(Trie*& node, char ch)
    {
        if (node == nullptr || node->_children[ch - 'a'] == nullptr)
        {
            node = nullptr;
            return false;
        }

        node = node->_children[ch - 'a'];
        return node->_is_end;
    }

    Trie() : _is_end(false)
    {
        _children.fill(nullptr);
    }

    void Insert(const std::string& word)
    {
        auto node{this};
        for (const auto& ch: word)
        {
            if (node->_children[ch - 'a'] == nullptr)
                node->_children[ch - 'a'] = new Trie();

            node = node->_children[ch - 'a'];
        }
        node->_is_end = true;
    }
};

class Solution
{
public:
    int minExtraChar(const std::string& s, std::vector<std::string>& dictionary)
    {
        Trie trie;
        for (const auto& word: dictionary)
        {
            auto reversed{word};
            std::reverse(reversed.begin(), reversed.end());
            trie.Insert(reversed);
        }

        std::vector<int> dp(s.size() + 1, INT_MAX);
        dp[0] = 0;

        for (int i{1}; i < dp.size(); ++i)
        {
            auto node{&trie};
            dp[i] = dp[i - 1] + 1;
            for (int j{i - 1}; j >= 0; --j)
            {
                if (Trie::Track(node, s[j]))
                    dp[i] = std::min(dp[i], dp[j]);
            }
        }

        return dp.back();
    }
};
}