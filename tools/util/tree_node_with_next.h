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
  if (values.empty()) {
    return nullptr;
  }

  auto root = new Node(values.front().value());

  std::queue<Node *> queue;
  queue.push(root);

  size_t i = 1;
  while (!queue.empty()) {
    auto node = queue.front();
    queue.pop();

    if (i < values.size() && values[i].has_value()) {
      node->left = new Node(values[i].value());
      queue.push(node->left);
    }
    ++i;
    if (i < values.size() && values[i].has_value()) {
      node->right = new Node(values[i].value());
      queue.push(node->right);
    }
    ++i;
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
