#pragma once

#include <cassert>
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

bool IsEqual(const TreeNode *node1, const TreeNode *node2) {
  if (!node1 && !node2) {
    return true;
  }
  if ((node1 && !node2) || (!node1 && node2) || node1->val != node2->val) {
    return false;
  }

  return IsEqual(node1->left, node2->left) &&
         IsEqual(node1->right, node2->right);
}

TreeNode *Copy(TreeNode *node) {
  if (node) {
    return new TreeNode(node->val, Copy(node->left), Copy(node->right));
  }
  return nullptr;
}

class Tree {
public:
  enum class Order {
    kPreOrder,
    kInOrder,
    kPostOrder,
  };

  Tree() : root_(nullptr) {}

  Tree(const Tree &other) : root_(Copy(other.root_)) {}

  Tree(Tree &&other) : Tree() { Swap(other); }

  Tree(std::initializer_list<std::optional<int>> list) : Tree() {
    if (list.size() == 0) {
      return;
    }

    auto it = list.begin();
    assert(it->has_value());
    root_ = new TreeNode(it->value());
    ++it;

    std::queue<TreeNode *> queue{{root_}};
    while (!queue.empty()) {
      auto node = queue.front();
      queue.pop();

      if (it != list.end()) {
        if (it->has_value()) {
          node->left = new TreeNode(it->value());
          queue.push(node->left);
        }
        ++it;
      }

      if (it != list.end()) {
        if (it->has_value()) {
          node->right = new TreeNode(it->value());
          queue.push(node->right);
        }
        ++it;
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

  TreeNode *Find(int value) const { return Find(root_, value); }

  std::vector<int> Traverse(Order order) const {
    std::vector<int> values;
    if (order == Order::kPreOrder) {
      TraversePreOrder(root_, &values);
    } else if (order == Order::kInOrder) {
      TraverseInOrder(root_, &values);
    } else if (order == Order::kPostOrder) {
      TraversePostOrder(root_, &values);
    } else {
      throw;
    }
    return values;
  }

  bool IsValidBST() const { return IsValidBST(root_, nullptr, nullptr); }
  bool IsBalanced() const { return IsBalancedWithDepth(root_).first; }

private:
  void Clear(TreeNode *node) {
    if (node) {
      Clear(node->left);
      Clear(node->right);
      delete node;
    }
  }

  TreeNode *Find(TreeNode *node, int val) const {
    if (!node || node->val == val) {
      return node;
    }
    auto left = Find(node->left, val);
    return left ? left : Find(node->right, val);
  }

  void TraversePreOrder(TreeNode *node, std::vector<int> *values) const {
    if (!node) {
      return;
    }
    values->push_back(node->val);
    TraversePreOrder(node->left, values);
    TraversePreOrder(node->right, values);
  }

  void TraverseInOrder(TreeNode *node, std::vector<int> *values) const {
    if (!node) {
      return;
    }
    TraverseInOrder(node->left, values);
    values->push_back(node->val);
    TraverseInOrder(node->right, values);
  }

  void TraversePostOrder(TreeNode *node, std::vector<int> *values) const {
    if (!node) {
      return;
    }
    TraversePostOrder(node->left, values);
    TraversePostOrder(node->right, values);
    values->push_back(node->val);
  }

  bool IsValidBST(TreeNode *node, TreeNode *min_node,
                  TreeNode *max_node) const {
    if (!node) {
      return true;
    }
    if ((min_node && min_node->val >= node->val) ||
        (max_node && node->val >= max_node->val)) {
      return false;
    }

    return IsValidBST(node->left, min_node, node) &&
           IsValidBST(node->right, node, max_node);
  }

  std::pair<bool, int> IsBalancedWithDepth(TreeNode *node) const {
    if (!node) {
      return {true, 0};
    }
    const auto [is_left_balanced, left_depth] = IsBalancedWithDepth(node->left);
    const auto [is_right_balanced, right_depth] =
        IsBalancedWithDepth(node->right);
    const auto is_balanced = is_left_balanced && is_right_balanced &&
                             abs(left_depth - right_depth) <= 1;
    return {is_balanced, 1 + std::max(left_depth, right_depth)};
  }

  TreeNode *root_;
};
