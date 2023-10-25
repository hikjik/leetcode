#pragma once

#include <tree_node.h>

class Solution {
public:
  static TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                                 TreeNode *target) {
    if (!original) {
      return nullptr;
    }
    if (original == target) {
      return cloned;
    }
    if (auto left = getTargetCopy(original->left, cloned->left, target); left) {
      return left;
    }
    return getTargetCopy(original->right, cloned->right, target);
  }
};
