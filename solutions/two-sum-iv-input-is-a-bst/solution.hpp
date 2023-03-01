#pragma once

#include <tree_node.h>

#include <unordered_set>

class Solution {
public:
  static bool findTarget(TreeNode *root, int target) {
    std::unordered_set<int> seen;
    return traverseInOrder(root, target, &seen);
  }

private:
  static bool traverseInOrder(TreeNode *node, int target,
                              std::unordered_set<int> *seen) {
    if (!node) {
      return false;
    }

    if (traverseInOrder(node->left, target, seen) || seen->count(node->val)) {
      return true;
    }
    seen->insert(target - node->val);
    return traverseInOrder(node->right, target, seen);
  }
};
