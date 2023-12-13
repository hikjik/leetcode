#pragma once

#include <span>
#include <unordered_map>
#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static TreeNode *constructFromPrePost(const std::vector<int> &preorder,
                                        const std::vector<int> &postorder) {
    std::unordered_map<int, int> indexes;
    for (int i = 0; i < std::ssize(postorder); ++i) {
      indexes[postorder[i]] = i;
    }
    return buildTree(std::span{preorder}, std::span{postorder}, indexes);
  }

private:
  static TreeNode *buildTree(std::span<const int> preorder,
                             std::span<const int> postorder,
                             const std::unordered_map<int, int> &indexes) {
    if (preorder.empty()) {
      return nullptr;
    }
    if (preorder.size() == 1) {
      return new TreeNode(preorder.front());
    }

    const auto left_size =
        indexes.at(preorder[1]) - indexes.at(postorder[0]) + 1;
    const auto right_size = preorder.size() - left_size - 1;
    return new TreeNode(preorder.front(),
                        buildTree(preorder.subspan(1, left_size),
                                  postorder.subspan(0, left_size), indexes),
                        buildTree(preorder.subspan(left_size + 1, right_size),
                                  postorder.subspan(left_size, right_size),
                                  indexes));
  }
};
