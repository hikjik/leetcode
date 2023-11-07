#pragma once

#include <tree_node.h>

#include <span>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static TreeNode *buildTree(const std::vector<int> &inorder,
                             const std::vector<int> &postorder) {
    std::unordered_map<int, int> indexes;
    for (int i = 0; i < std::ssize(inorder); ++i) {
      indexes[inorder[i]] = i;
    }
    return buildTree(std::span{postorder}, std::span{inorder}, indexes);
  }

private:
  static TreeNode *buildTree(std::span<const int> postorder,
                             std::span<const int> inorder,
                             const std::unordered_map<int, int> &indexes) {
    if (postorder.empty()) {
      return nullptr;
    }
    const auto left_size =
        indexes.at(postorder.back()) - indexes.at(inorder.front());
    const auto right_size = postorder.size() - left_size - 1;
    return new TreeNode(postorder.back(),
                        buildTree(postorder.subspan(0, left_size),
                                  inorder.subspan(0, left_size), indexes),
                        buildTree(postorder.subspan(left_size, right_size),
                                  inorder.subspan(left_size + 1), indexes));
  }
};
