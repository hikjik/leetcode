#pragma once

#include <tree_node.h>

#include <unordered_map>
#include <vector>

class Solution {
public:
  static TreeNode *buildTree(const std::vector<int> &preorder,
                             const std::vector<int> &in_order) {
    std::unordered_map<int, int> positions;
    for (size_t i = 0; i < in_order.size(); ++i) {
      positions[in_order[i]] = i;
    }
    return buildTree(0, preorder.size() - 1, preorder, 0, in_order.size() - 1,
                     in_order, positions);
  }

private:
  static TreeNode *
  buildTree(int left_pre, int right_pre, const std::vector<int> &preorder,
            int left_in, int right_in, const std::vector<int> &in_order,
            const std::unordered_map<int, int> &in_order_positions) {
    if (left_in > right_in) {
      return nullptr;
    }

    auto root_val = preorder[left_pre];
    auto root_pos = in_order_positions.at(root_val);

    return new TreeNode(
        root_val,
        buildTree(left_pre + 1, left_pre + root_pos - left_in, preorder,
                  left_in, root_pos - 1, in_order, in_order_positions),
        buildTree(left_pre + root_pos - left_in + 1, right_pre, preorder,
                  root_pos + 1, right_in, in_order, in_order_positions));
  }
};