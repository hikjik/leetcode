#pragma once

#include <queue>

#include <node.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time: O(N)
// Space: O(N)

class Codec {
public:
  static TreeNode *encode(Node *nRoot) {
    if (!nRoot) {
      return nullptr;
    }

    auto *bRoot = new TreeNode(nRoot->val);
    std::queue<std::pair<Node *, TreeNode *>> queue{{{nRoot, bRoot}}};
    for (bool left = true; !queue.empty(); left = !left) {
      for (int sz = queue.size(); sz; --sz) {
        auto [nNode, bNode] = queue.front();
        queue.pop();

        for (auto *nChild : nNode->children) {
          auto *bChild = new TreeNode(nChild->val);
          if (left) {
            bNode->left = bChild;
          } else {
            bNode->right = bChild;
          }
          queue.push({nChild, bChild});
          bNode = bChild;
        }
      }
    }
    return bRoot;
  }

  static Node *decode(TreeNode *bRoot) {
    if (!bRoot) {
      return nullptr;
    }

    auto *nRoot = new Node(bRoot->val);
    std::queue<std::pair<TreeNode *, Node *>> queue{{{bRoot, nRoot}}};
    for (bool left = true; !queue.empty(); left = !left) {
      for (int sz = queue.size(); sz; --sz) {
        auto [bNode, nNode] = queue.front();
        queue.pop();
        for (auto *bChild = left ? bNode->left : bNode->right; bChild;
             bChild = left ? bChild->left : bChild->right) {
          auto *nChild = new Node(bChild->val);
          nNode->children.push_back(nChild);
          queue.push({bChild, nChild});
        }
      }
    }
    return nRoot;
  }
};
