#pragma once

#include <optional>
#include <queue>
#include <vector>

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

Node *VectorToTree(const std::vector<std::optional<int>> &values) {
  if (values.empty() || !values[0].has_value()) {
    return nullptr;
  }

  auto root = new Node(values[0].value());
  std::queue<std::pair<Node *, size_t>> items;
  items.emplace(root, 0);
  while (!items.empty()) {
    const auto &[node, index] = items.front();
    items.pop();

    const auto left = 2 * index + 1;
    if (left < values.size() && values[left].has_value()) {
      node->left = new Node(values[left].value());
      items.emplace(node->left, left);
    }

    const auto right = 2 * index + 2;
    if (right < values.size() && values[right].has_value()) {
      node->right = new Node(values[right].value());
      items.emplace(node->right, right);
    }
  }

  return root;
}

void FreeTree(Node *root) {
  if (!root) {
    return;
  }

  FreeTree(root->left);
  FreeTree(root->right);
  delete root;
}
