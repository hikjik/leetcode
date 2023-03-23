#pragma once

#include <optional>
#include <vector>

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

Node *
VectorToList(const std::vector<std::pair<int, std::optional<int>>> &values) {
  int n = values.size();
  std::vector<Node *> nodes(n, nullptr);

  Node dummy(0);
  auto node = &dummy;
  for (int i = 0; i < n; ++i) {
    node->next = new Node(values[i].first);
    node = node->next;
    nodes[i] = node;
  }

  for (int i = 0; i < n; ++i) {
    if (values[i].second) {
      const auto index = values[i].second.value();
      nodes[i]->random = nodes[index];
    }
  }
  return dummy.next;
}

void FreeList(Node *node) {
  while (node) {
    auto next = node->next;
    delete node;
    node = next;
  }
}
