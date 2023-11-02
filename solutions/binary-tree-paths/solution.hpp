#pragma once

#include <sstream>
#include <string>
#include <vector>

#include <tree_node.h>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::string> binaryTreePaths(TreeNode *root) {
    std::vector<std::string> paths;
    std::vector<std::string> path;
    binaryTreePaths(root, &path, &paths);
    return paths;
  }

private:
  static void binaryTreePaths(TreeNode *node, std::vector<std::string> *path,
                              std::vector<std::string> *paths) {
    if (!node) {
      return;
    }

    if (!node->left && !node->right) {
      paths->push_back(join(path) + std::to_string(node->val));
      return;
    }

    path->push_back(std::to_string(node->val) + "->");
    binaryTreePaths(node->left, path, paths);
    binaryTreePaths(node->right, path, paths);
    path->pop_back();
  }

  static std::string join(const std::vector<std::string> *path) {
    std::stringstream sstream;
    for (const auto &p : *path) {
      sstream << p;
    }
    return sstream.str();
  }
};
