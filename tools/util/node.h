#pragma once

#include <cassert>
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

Node *Copy(Node *node) {
  if (node) {
    std::vector<Node *> children;
    for (auto *child : node->children) {
      children.push_back(Copy(child));
    }
    return new Node(node->val, std::move(children));
  }
  return nullptr;
}

class Tree {
public:
  Tree() : root_(nullptr) {}

  Tree(const Tree &other) : root_(Copy(other.root_)) {}

  Tree(Tree &&other) : Tree() { Swap(other); }

  Tree(std::initializer_list<std::optional<int>> list) : Tree() {
    if (list.size() == 0) {
      return;
    }

    auto it = list.begin();
    assert(it->has_value());
    root_ = new Node(it->value());
    ++it;

    std::queue<Node *> queue;
    queue.push(root_);

    while (!queue.empty()) {
      auto node = queue.front();
      queue.pop();

      if (it != list.end()) {
        ++it;
      }

      while (it != list.end() && it->has_value()) {
        auto child = new Node(it->value());
        node->children.push_back(child);
        queue.push(child);
        ++it;
      }
    }
  }

  Tree(Node *root) { root_ = root; }

  Tree &operator=(Tree other) {
    Swap(other);
    return *this;
  }

  void Swap(Tree &other) { std::swap(root_, other.root_); }

  ~Tree() { Clear(root_); }

  operator Node *() const { return root_; }

  const Node *Root() const { return root_; }

  friend bool operator==(const Tree &lhs, const Tree &rhs) {
    std::queue<std::pair<Node *, Node *>> queue;
    queue.push({lhs.root_, rhs.root_});
    while (!queue.empty()) {
      const auto [node1, node2] = queue.front();
      queue.pop();

      if (!node1 && node2 || node1 && !node2) {
        return false;
      }
      if (!node1 && !node2) {
        continue;
      }
      if (node1->val != node2->val) {
        return false;
      }
      if (node1->children.size() != node2->children.size()) {
        return false;
      }
      for (int i = 0; i < std::ssize(node1->children); ++i) {
        queue.push({node1->children[i], node2->children[i]});
      }
    }
    return true;
  }

private:
  void Clear(Node *node) {
    if (!node) {
      return;
    }

    for (auto child : node->children) {
      Clear(child);
    }

    delete node;
  }

  Node *root_;
};
