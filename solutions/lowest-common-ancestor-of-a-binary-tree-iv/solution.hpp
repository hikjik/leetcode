#pragma once

#include <ranges>
#include <unordered_set>
#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static TreeNode *lowestCommonAncestor(TreeNode *root,
                                        const std::vector<TreeNode *> &nodes) {
    std::unordered_set<TreeNode *> nodesSet{nodes.begin(), nodes.end()};
    return lca(root, nodesSet);
  }

private:
  static TreeNode *lca(TreeNode *root,
                       const std::unordered_set<TreeNode *> &nodes) {
    if (!root) {
      return nullptr;
    }

    if (std::ranges::find(nodes, root) != nodes.end()) {
      return root;
    }

    auto *left = lca(root->left, nodes);
    auto *right = lca(root->right, nodes);
    return left && right ? root : left ? left : right;
  }
};
