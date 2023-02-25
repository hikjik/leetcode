#pragma once

#include <tree_node.h>

#include <vector>

class Solution {
public:
  static std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> values;
    traverseInPreOrder(root, &values);
    return values;
  }

private:
  static void traverseInPreOrder(TreeNode *root, std::vector<int> *values) {
    if (!root) {
      return;
    }

    values->push_back(root->val);
    traverseInPreOrder(root->left, values);
    traverseInPreOrder(root->right, values);
  }
};
