#pragma once

#include "tree_node.h"

#include <vector>

class Solution {
public:
  static std::vector<TreeNode *> allPossibleFBT(int n) {
    if (n % 2 == 0) {
      return {};
    }

    if (n == 1) {
      return {new TreeNode(0)};
    }

    std::vector<TreeNode *> trees;
    for (int i = 1; i < n; i += 2) {
      const auto left = allPossibleFBT(i);
      const auto right = allPossibleFBT(n - i - 1);

      for (auto l : left) {
        for (auto r : right) {
          trees.push_back(new TreeNode(0, l, r));
        }
      }
    }
    return trees;
  }
};
