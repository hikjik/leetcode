#pragma once

#include <tree_node.h>

#include <vector>

// Time: O(N^2)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<int>> pathSum(TreeNode *root, int target) {
    std::vector<int> path;
    std::vector<std::vector<int>> paths;
    pathSum(root, target, &path, &paths);
    return paths;
  }

private:
  static void pathSum(TreeNode *root, int target, std::vector<int> *path,
                      std::vector<std::vector<int>> *paths) {
    if (!root) {
      return;
    }
    path->push_back(root->val);
    if (!root->left && !root->right) {
      if (target == root->val) {
        paths->push_back(*path);
      }
    } else {
      target -= root->val;
      pathSum(root->left, target, path, paths);
      pathSum(root->right, target, path, paths);
    }
    path->pop_back();
  }
};
