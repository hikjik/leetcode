#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

struct RopeTreeNode {
  int len;
  std::string val;
  RopeTreeNode *left;
  RopeTreeNode *right;
  RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
  RopeTreeNode(std::string s)
      : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
  RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
  RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right)
      : len(x), val(""), left(left), right(right) {}
};

namespace recursive {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static char getKthCharacter(RopeTreeNode *root, int k) {
    if (!root->len) {
      return root->val[k - 1];
    }
    const int len = root->left ? root->left->len + root->left->val.size() : 0;
    return len >= k ? getKthCharacter(root->left, k)
                    : getKthCharacter(root->right, k - len);
  }
};

} // namespace recursive

namespace iterative {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static char getKthCharacter(RopeTreeNode *root, int k) {
    while (root->len) {
      const int len = root->left ? root->left->len + root->left->val.size() : 0;
      if (len >= k) {
        root = root->left;
      } else {
        root = root->right;
        k -= len;
      }
    }
    return root->val[k - 1];
  }
};

} // namespace iterative
