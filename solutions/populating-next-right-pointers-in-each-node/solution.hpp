#pragma once

#include <tree_node_with_next.h>

/*
  116. Populating Next Right Pointers in Each Node
  https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
  Difficulty: Medium
  Tags: Linked List, Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static Node *connect(Node *root) {
    if (!root) {
      return nullptr;
    }

    if (root->left) {
      root->left->next = root->right;
    }

    if (root->right && root->next) {
      root->right->next = root->next->left;
    }

    connect(root->left);
    connect(root->right);

    return root;
  }
};
