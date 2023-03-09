#pragma once

#include <tree_node.h>

#include <vector>

class Solution {
public:
  static int pathSum(TreeNode *root, int target) {
    if (!root) {
      return 0;
    }
    return continuousPathSum(root, target) + pathSum(root->left, target) +
           pathSum(root->right, target);
  }

private:
  static int continuousPathSum(TreeNode *root, long long target) {
    if (!root) {
      return 0;
    }
    return (root->val == target) +
           continuousPathSum(root->left, target - root->val) +
           continuousPathSum(root->right, target - root->val);
  }
};
