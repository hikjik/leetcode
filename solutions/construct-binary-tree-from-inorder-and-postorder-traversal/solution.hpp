#pragma once

#include <tree_node.h>

#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static TreeNode *buildTree(const std::vector<int> &in_order,
                             const std::vector<int> &postorder) {
    std::unordered_map<int, int> positions;
    for (size_t i = 0; i < in_order.size(); ++i) {
      positions[in_order[i]] = i;
    }
    return buildTree(0, in_order.size() - 1, in_order, 0, postorder.size() - 1,
                     postorder, positions);
  }

private:
  static TreeNode *
  buildTree(int left_in, int right_in, const std::vector<int> &in_order,
            int left_post, int right_post, const std::vector<int> &postorder,
            const std::unordered_map<int, int> &in_order_positions) {
    if (left_in > right_in) {
      return nullptr;
    }

    auto root_val = postorder[right_post];
    auto root_pos = in_order_positions.at(root_val);

    return new TreeNode(root_val,
                        buildTree(left_in, root_pos - 1, in_order, left_post,
                                  left_post + root_pos - left_in - 1, postorder,
                                  in_order_positions),
                        buildTree(root_pos + 1, right_in, in_order,
                                  left_post + root_pos - left_in,
                                  right_post - 1, postorder,
                                  in_order_positions));
  }
};
