#pragma once

#include <tree_node.h>

#include <map>
#include <vector>

// Time:
// Space:

class Solution {
private:
  using Memo = std::map<std::pair<int, int>, std::vector<TreeNode *>>;

public:
  static std::vector<TreeNode *> generateTrees(int n) {
    Memo memo;
    return generateTrees(1, n, &memo);
  }

private:
  static std::vector<TreeNode *> generateTrees(int left, int right,
                                               Memo *memo) {
    if (left > right) {
      return {nullptr};
    }

    const auto key = std::make_pair(left, right);
    if (auto it = memo->find(key); it != memo->end()) {
      return it->second;
    }

    auto &trees = (*memo)[key];
    for (int middle = left; middle <= right; ++middle) {
      const auto left_trees = generateTrees(left, middle - 1, memo);
      const auto right_trees = generateTrees(middle + 1, right, memo);

      for (auto *left_tree : left_trees) {
        for (auto *right_tree : right_trees) {
          trees.push_back(new TreeNode(middle, left_tree, right_tree));
        }
      }
    }
    return trees;
  }
};
