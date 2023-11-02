#pragma once

#include <string>

#include <tree_node.h>

// Time:
// Space:

class Solution {
public:
  static std::string tree2str(TreeNode *root) {
    if (!root) {
      return "";
    }
    std::string str = std::to_string(root->val);
    if (root->right) {
      str += "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    } else if (root->left) {
      str += "(" + tree2str(root->left) + ")";
    }
    return str;
  }
};
