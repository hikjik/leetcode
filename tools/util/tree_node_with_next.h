#pragma once

#include <cassert>
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

Node *Copy(Node *node) {
  if (node) {
    assert(!node->next);

    return new Node(node->val, Copy(node->left), Copy(node->right), nullptr);
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

    std::queue<Node *> queue{{root_}};
    while (!queue.empty()) {
      auto node = queue.front();
      queue.pop();

      if (it != list.end()) {
        if (it->has_value()) {
          node->left = new Node(it->value());
          queue.push(node->left);
        }
        ++it;
      }

      if (it != list.end()) {
        if (it->has_value()) {
          node->right = new Node(it->value());
          queue.push(node->right);
        }
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
    if (node) {
      Clear(node->left);
      Clear(node->right);
      delete node;
    }
  }

  Node *root_;
};
