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
  Node *parent;

  Node() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), parent(nullptr) {}

  Node(int _val, Node *_left, Node *_right, Node *_parent)
      : val(_val), left(_left), right(_right), parent(_parent) {}
};

Node *Copy(Node *node, Node *parent = nullptr) {
  if (node) {
    auto *copy = new Node(node->val, nullptr, nullptr, parent);
    copy->left = Copy(node->left, copy);
    copy->right = Copy(node->right, copy);
    return copy;
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
      auto *node = queue.front();
      queue.pop();

      if (it != list.end()) {
        if (it->has_value()) {
          node->left = new Node(it->value());
          node->left->parent = node;
          queue.push(node->left);
        }
        ++it;
      }

      if (it != list.end()) {
        if (it->has_value()) {
          node->right = new Node(it->value());
          node->right->parent = node;
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

  Node *Find(int val) const { return Find(root_, val); }

private:
  void Clear(Node *node) {
    if (node) {
      Clear(node->left);
      Clear(node->right);
      delete node;
    }
  }

  Node *Find(Node *node, int val) const {
    if (!node || node->val == val) {
      return node;
    }
    auto left = Find(node->left, val);
    return left ? left : Find(node->right, val);
  }

  Node *root_;
};
