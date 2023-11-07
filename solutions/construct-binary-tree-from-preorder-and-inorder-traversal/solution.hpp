#pragma once

#include <tree_node.h>

#include <span>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static TreeNode *buildTree(const std::vector<int> &preorder,
                             const std::vector<int> &inorder) {
    std::unordered_map<int, int> indexes;
    for (int i = 0; i < std::ssize(inorder); ++i) {
      indexes[inorder[i]] = i;
    }
    return buildTree(std::span{preorder}, std::span{inorder}, indexes);
  }

private:
  static TreeNode *buildTree(std::span<const int> preorder,
                             std::span<const int> inorder,
                             const std::unordered_map<int, int> &indexes) {
    if (preorder.empty()) {
      return nullptr;
    }
    const auto left_size = indexes.at(preorder[0]) - indexes.at(inorder[0]);
    return new TreeNode(preorder[0],
                        buildTree(preorder.subspan(1, left_size),
                                  inorder.subspan(0, left_size), indexes),
                        buildTree(preorder.subspan(left_size + 1),
                                  inorder.subspan(left_size + 1), indexes));
  }
};
