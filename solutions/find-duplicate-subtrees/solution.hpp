#pragma once

#include <tree_node.h>

#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    std::unordered_map<std::string, int> ids;
    std::unordered_map<int, int> counter;
    std::vector<TreeNode *> duplicates;
    TraverseTree(root, &ids, &counter, &duplicates);
    return duplicates;
  }

private:
  static int TraverseTree(TreeNode *node,
                          std::unordered_map<std::string, int> *ids,
                          std::unordered_map<int, int> *counter,
                          std::vector<TreeNode *> *duplicates) {
    if (!node) {
      return 0;
    }
    const auto left = TraverseTree(node->left, ids, counter, duplicates);
    const auto right = TraverseTree(node->right, ids, counter, duplicates);
    const auto triplet = std::to_string(left) + "|" +
                         std::to_string(node->val) + "|" +
                         std::to_string(right);
    if (!ids->count(triplet)) {
      (*ids)[triplet] = ids->size() + 1;
    }
    const auto id = (*ids)[triplet];
    ++(*counter)[id];
    if ((*counter)[id] == 2) {
      duplicates->push_back(node);
    }
    return id;
  }
};
