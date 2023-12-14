#pragma once

#include "next_tree_node.h"

#include <queue>
#include <algorithm>
#include <memory>

namespace leetcode_117 {

class Solution
{
public:
    Node* connect(Node* root)
    {
        if (!root)return root;

        auto start_node_ptr{root};
        while (start_node_ptr)
        {
            Node* next_layer_start_node_ptr{nullptr};
            Node* wait_next_connect_node_prt{nullptr};

            while (start_node_ptr)
            {
                if (start_node_ptr->left)
                    ConnectNode(wait_next_connect_node_prt, start_node_ptr->left, next_layer_start_node_ptr);
                if (start_node_ptr->right)
                    ConnectNode(wait_next_connect_node_prt, start_node_ptr->right, next_layer_start_node_ptr);

                start_node_ptr = start_node_ptr->next;
            }

            start_node_ptr = next_layer_start_node_ptr;
        }

        return root;
    }

    void ConnectNode(Node*& wait_next_node,
                     Node*& next_node,
                     Node*& next_layer_start_node)
    {
        if (!next_layer_start_node)
            next_layer_start_node = next_node;

        if (!wait_next_node)
            wait_next_node = next_node;
        else
            wait_next_node->next = next_node;

        wait_next_node = next_node;
    }
};

}

