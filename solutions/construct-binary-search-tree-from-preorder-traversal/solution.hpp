#pragma once

#include <climits>
#include <span>
#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(logN)

namespace bs {

// Time: O(NlogN)
// Space: O(logN)
class Solution {
public:
  static TreeNode *bstFromPreorder(const std::vector<int> &preorder) {
    return bstFromPreorder(std::span{preorder});
  }

private:
  static TreeNode *bstFromPreorder(std::span<const int> preorder) {
    if (preorder.empty()) {
      return nullptr;
    }

    const auto root = preorder[0];

    int left = 1, right = preorder.size();
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      preorder[middle] < root ? left = middle + 1 : right = middle;
    }

    return new TreeNode(root, bstFromPreorder(preorder.subspan(1, right - 1)),
                        bstFromPreorder(preorder.subspan(right)));
  }
};

} // namespace bs

namespace linear {

// Time: O(N)
// Space: O(logN)
class Solution {
public:
  static TreeNode *bstFromPreorder(const std::vector<int> &preorder) {
    int idx = 0;
    return bstFromPreorder(preorder, INT_MAX, &idx);
  }

private:
  static TreeNode *bstFromPreorder(const std::vector<int> &preorder, int max,
                                   int *idx) {
    if (*idx == std::ssize(preorder) || preorder[*idx] > max) {
      return nullptr;
    }
    const auto root = preorder[(*idx)++];
    return new TreeNode(root, bstFromPreorder(preorder, root, idx),
                        bstFromPreorder(preorder, max, idx));
  }
};

} // namespace linear
