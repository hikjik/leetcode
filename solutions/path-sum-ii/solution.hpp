#pragma once

#include <tree_node.h>

#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>> pathSum(TreeNode *root, int target) {
    std::vector<std::vector<int>> paths;
    std::vector<int> path;
    pathSum(root, target, &paths, &path);
    return paths;
  }

private:
  static void pathSum(TreeNode *root, int target,
                      std::vector<std::vector<int>> *paths,
                      std::vector<int> *path) {
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
      pathSum(root->left, target, paths, path);
      pathSum(root->right, target, paths, path);
    }
    path->pop_back();
  }
};
