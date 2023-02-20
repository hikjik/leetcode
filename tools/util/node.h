#pragma once

#include <optional>
#include <queue>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, std::vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

Node *VectorToNAryTree(const std::vector<std::optional<int>> &values) {
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

    for (++i; i < values.size() && values[i].has_value(); ++i) {
      auto child = new Node(values[i].value());
      node->children.push_back(child);
      queue.push(child);
    }
  }

  return root;
}

void FreeNAryTree(Node *root) {
  if (!root) {
    return;
  }

  for (auto child : root->children) {
    FreeNAryTree(child);
  }

  delete root;
}
