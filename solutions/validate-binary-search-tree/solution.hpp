#pragma once

#include <tree_node.h>

#include <vector>

class Solution {
public:
  static bool isValidBST(TreeNode *root) {
    std::vector<int> values;
    traverseInOrder(root, &values);
    return isStrictlySorted(values);
  }

private:
  static void traverseInOrder(TreeNode *root, std::vector<int> *values) {
    if (!root) {
      return;
    }

    traverseInOrder(root->left, values);
    values->push_back(root->val);
    traverseInOrder(root->right, values);
  }

  static bool isStrictlySorted(const std::vector<int> &values) {
    for (size_t i = 1; i < values.size(); ++i) {
      if (values[i - 1] >= values[i]) {
        return false;
      }
    }
    return true;
  }
};
