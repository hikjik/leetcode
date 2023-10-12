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
