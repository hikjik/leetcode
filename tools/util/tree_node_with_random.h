#pragma once

#include <cassert>
#include <optional>
#include <queue>
#include <unordered_map>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *random;
  TreeNode() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *random)
      : val(x), left(left), right(right), random(random) {}
};

bool IsEqual(const TreeNode *root1, const TreeNode *root2) {
  std::unordered_map<const TreeNode *, const TreeNode *> map;
  std::queue<std::pair<const TreeNode *, const TreeNode *>> queue{
      {{root1, root2}}};
  while (!queue.empty()) {
    const auto [node1, node2] = queue.front();
    queue.pop();

    if (!node1 && !node2) {
      continue;
    }

    if ((node1 && !node2) || (!node1 && node2) || node1->val != node2->val) {
      return false;
    }

    map[node1] = node2;

    queue.emplace(node1->left, node2->left);
    queue.emplace(node1->right, node2->right);
  }

  queue.emplace(root1, root2);
  while (!queue.empty()) {
    const auto [node1, node2] = queue.front();
    queue.pop();

    if (node1 && node2) {
      if (map[node1->random] != node2->random) {
        return false;
      }
      queue.emplace(node1->left, node2->left);
      queue.emplace(node1->right, node2->right);
    }
  }
  return true;
}

TreeNode *Copy(TreeNode *root) {
  if (!root) {
    return nullptr;
  }

  std::unordered_map<TreeNode *, TreeNode *> map{
      {root, new TreeNode(root->val)}};
  std::queue<TreeNode *> queue{{root}};
  while (!queue.empty()) {
    auto *node = queue.front();
    queue.pop();

    if (node->left) {
      map[node]->left = map[node->left] = new TreeNode(node->left->val);
      queue.push(node->left);
    }

    if (node->right) {
      map[node]->right = map[node->right] = new TreeNode(node->right->val);
      queue.push(node->right);
    }
  }

  queue.push(root);
  while (!queue.empty()) {
    auto *node = queue.front();
    queue.pop();

    if (node->random) {
      map[node]->random = map[node->random];
    }

    for (auto *child : {node->left, node->right}) {
      if (child) {
        queue.push(child);
      }
    }
  }

  return map[root];
}

class Tree {
public:
  Tree() : root_(nullptr) {}

  Tree(const Tree &other) : root_(Copy(other.root_)) {}

  Tree(Tree &&other) : Tree() { Swap(other); }

  Tree(std::initializer_list<std::initializer_list<std::optional<int>>> list)
      : Tree() {
    if (list.size() == 0) {
      return;
    }

    std::vector<TreeNode *> nodes;
    for (const auto &p : list) {
      if (p.size() > 0) {
        nodes.push_back(new TreeNode(p.begin()->value()));
      } else {
        nodes.push_back(nullptr);
      }
    }

    for (int i = 0; const auto &p : list) {
      if (nodes[i]) {
        const auto it_random = std::next(p.begin());
        if (it_random->has_value()) {
          nodes[i]->random = nodes[it_random->value()];
        }
      }
      ++i;
    }

    root_ = nodes.front();

    std::queue<TreeNode *> queue{{root_}};
    for (int i = 1; !queue.empty();) {
      auto node = queue.front();
      queue.pop();

      if (i < std::ssize(nodes)) {
        if (nodes[i]) {
          node->left = nodes[i];
          queue.push(node->left);
        }
        ++i;
      }

      if (i < std::ssize(nodes)) {
        if (nodes[i]) {
          node->right = nodes[i];
          queue.push(node->right);
        }
        ++i;
      }
    }
  }

  Tree(TreeNode *root) { root_ = root; }

  Tree &operator=(Tree other) {
    Swap(other);
    return *this;
  }

  void Swap(Tree &other) { std::swap(root_, other.root_); }

  ~Tree() { Clear(root_); }

  operator TreeNode *() const { return root_; }

  friend bool operator==(const Tree &lhs, const Tree &rhs) {
    return IsEqual(lhs.root_, rhs.root_);
  }

private:
  void Clear(TreeNode *node) {
    if (node) {
      Clear(node->left);
      Clear(node->right);
      delete node;
    }
  }

  TreeNode *root_;
};
