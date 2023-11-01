#pragma once

#include <tree_node_with_next.h>

/*
  117. Populating Next Right Pointers in Each Node II
  https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
  Difficulty: Medium
  Tags: Linked List, Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static Node *connect(Node *root) {
    auto node = root;
    while (node) {
      Node dummy;
      for (auto tail = &dummy; node; node = node->next) {
        if (node->left) {
          tail->next = node->left;
          tail = tail->next;
        }
        if (node->right) {
          tail->next = node->right;
          tail = tail->next;
        }
      }
      node = dummy.next;
    }
    return root;
  }
};
