#pragma once

#include <optional>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *VectorToTree(const std::vector<std::optional<int>> &values) {
  if (values.empty() || !values[0].has_value()) {
    return nullptr;
  }

  auto root = new TreeNode(values[0].value());
  std::queue<std::pair<TreeNode *, size_t>> items;
  items.emplace(root, 0);
  while (!items.empty()) {
    const auto &[node, index] = items.front();
    items.pop();

    const auto left = 2 * index + 1;
    if (left < values.size() && values[left].has_value()) {
      node->left = new TreeNode(values[left].value());
      items.emplace(node->left, left);
    }

    const auto right = 2 * index + 2;
    if (right < values.size() && values[right].has_value()) {
      node->right = new TreeNode(values[right].value());
      items.emplace(node->right, right);
    }
  }

  return root;
}

void FreeTree(TreeNode *root) {
  if (!root) {
    return;
  }

  FreeTree(root->left);
  FreeTree(root->right);
  delete root;
}

bool EqualTree(TreeNode *root1, TreeNode *root2) {
  if (!root1 && !root2) {
    return true;
  }
  if (root1 && !root2 || !root1 && root2 || root1->val != root2->val) {
    return false;
  }

  return EqualTree(root1->left, root2->left) &&
         EqualTree(root1->right, root2->right);
}
