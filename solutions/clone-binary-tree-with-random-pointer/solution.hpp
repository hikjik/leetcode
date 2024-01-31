#pragma once

#include <functional>
#include <queue>
#include <unordered_map>

#include <tree_node_with_random.h>

// Time: O(N)
// Space: O(N)

using Node = TreeNode;
using NodeCopy = TreeNode;

namespace bfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static NodeCopy *copyRandomBinaryTree(Node *root) {
    if (!root) {
      return nullptr;
    }

    std::unordered_map<Node *, NodeCopy *> map{{root, new NodeCopy(root->val)}};
    std::queue<Node *> queue{{root}};
    while (!queue.empty()) {
      auto *node = queue.front();
      queue.pop();

      if (node->left) {
        map[node]->left = map[node->left] = new NodeCopy(node->left->val);
        queue.push(node->left);
      }

      if (node->right) {
        map[node]->right = map[node->right] = new NodeCopy(node->right->val);
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
};

} // namespace bfs

namespace dfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static NodeCopy *copyRandomBinaryTree(Node *root) {
    std::unordered_map<Node *, NodeCopy *> map;

    std::function<NodeCopy *(Node *)> mapNodes = [&](Node *node) -> NodeCopy * {
      if (!node) {
        return nullptr;
      }
      return map[node] = new NodeCopy(node->val, mapNodes(node->left),
                                      mapNodes(node->right), nullptr);
    };
    mapNodes(root);

    std::function<void(Node *)> mapRandom = [&](Node *node) {
      if (!node) {
        return;
      }
      map[node]->random = map[node->random];
      mapRandom(node->left);
      mapRandom(node->right);
    };
    mapRandom(root);

    return map[root];
  }
};

} // namespace dfs
