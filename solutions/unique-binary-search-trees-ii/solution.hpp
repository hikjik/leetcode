#pragma once

#include <tree_node.h>

#include <map>
#include <vector>

// Time: O(G(N)) - Catalan number
// Space: O(G(N))

namespace recursion {

// Time: O(G(N))
// Space: O(G(N))
class Solution {
public:
  static std::vector<TreeNode *> generateTrees(int n) {
    return generateTrees(1, n);
  }

private:
  static std::vector<TreeNode *> generateTrees(int left, int right) {
    if (left > right)
      return {nullptr};

    std::vector<TreeNode *> trees;
    for (int i = left; i <= right; ++i) {
      for (auto *left : generateTrees(left, i - 1)) {
        for (auto *right : generateTrees(i + 1, right)) {
          trees.push_back(new TreeNode(i, left, right));
        }
      }
    }
    return trees;
  }
};

} // namespace recursion

namespace memo {

// Time: O(G(N))
// Space: O(G(N))
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
    for (int i = left; i <= right; ++i) {
      for (auto *left_tree : generateTrees(left, i - 1, memo)) {
        for (auto *right_tree : generateTrees(i + 1, right, memo)) {
          trees.push_back(new TreeNode(i, left_tree, right_tree));
        }
      }
    }
    return trees;
  }
};

} // namespace memo
