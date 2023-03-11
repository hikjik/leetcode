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

TreeNode *Find(TreeNode *root, int val) {
  if (!root || root->val == val) {
    return root;
  }
  return val < root->val ? Find(root->left, val) : Find(root->right, val);
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

void TraversePreOrder(TreeNode *root, std::vector<int> *values) {
  if (!root) {
    return;
  }
  values->push_back(root->val);
  TraversePreOrder(root->left, values);
  TraversePreOrder(root->right, values);
}

std::vector<int> TraversePreOrder(TreeNode *root) {
  std::vector<int> values;
  TraversePreOrder(root, &values);
  return values;
}

void TraverseInOrder(TreeNode *root, std::vector<int> *values) {
  if (!root) {
    return;
  }
  TraverseInOrder(root->left, values);
  values->push_back(root->val);
  TraverseInOrder(root->right, values);
}

std::vector<int> TraverseInOrder(TreeNode *root) {
  std::vector<int> values;
  TraverseInOrder(root, &values);
  return values;
}

bool isValidBST(TreeNode *root, TreeNode *min_node, TreeNode *max_node) {
  if (!root) {
    return true;
  }
  if ((min_node && min_node->val >= root->val) ||
      (max_node && root->val >= max_node->val)) {
    return false;
  }

  return isValidBST(root->left, min_node, root) &&
         isValidBST(root->right, root, max_node);
}

std::pair<bool, int> isBalancedWithDepth(TreeNode *root) {
  if (!root) {
    return {true, 0};
  }
  const auto [is_left_balanced, left_depth] = isBalancedWithDepth(root->left);
  const auto [is_right_balanced, right_depth] =
      isBalancedWithDepth(root->right);
  const auto is_balanced = is_left_balanced && is_right_balanced &&
                           abs(left_depth - right_depth) <= 1;
  return {is_balanced, 1 + std::max(left_depth, right_depth)};
}

bool isValidBST(TreeNode *root) { return isValidBST(root, nullptr, nullptr); }
bool isBalanced(TreeNode *root) { return isBalancedWithDepth(root).first; }
