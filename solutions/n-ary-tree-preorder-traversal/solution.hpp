#pragma once

#include <node.h>

#include <vector>

/*
  589. N-ary Tree Preorder Traversal
  https://leetcode.com/problems/n-ary-tree-preorder-traversal/
  Difficulty: Easy
  Tags: Stack, Tree, Depth-First Search
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> preorder(Node *root) {
    std::vector<int> values;
    dfs(root, &values);
    return values;
  }

private:
  static void dfs(Node *node, std::vector<int> *values) {
    if (!node) {
      return;
    }

    values->push_back(node->val);
    for (auto child : node->children) {
      dfs(child, values);
    }
  }
};
