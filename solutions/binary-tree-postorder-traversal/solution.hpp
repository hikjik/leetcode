#pragma once

#include <tree_node.h>

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> values;
    traverseInPostOrder(root, &values);
    return values;
  }

private:
  static void traverseInPostOrder(TreeNode *root, std::vector<int> *values) {
    if (!root) {
      return;
    }

    traverseInPostOrder(root->left, values);
    traverseInPostOrder(root->right, values);
    values->push_back(root->val);
  }
};
