#pragma once

#include <tree_node.h>

// Time: O(N+M)
// Space: O(1)

namespace bs {

// Time: O(NM) worst case O(NlogM) for balanced trees
// Space: O(N+M)
class Solution {
public:
  static bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
    std::queue<TreeNode *> queue{{root1}};
    while (!queue.empty()) {
      auto *node = queue.front();
      queue.pop();

      if (find(root2, target - node->val)) {
        return true;
      }
      for (auto *child : {node->left, node->right}) {
        if (child) {
          queue.push(child);
        }
      }
    }
    return false;
  }

private:
  static bool find(TreeNode *node, int target) {
    if (!node) {
      return false;
    }
    if (node->val == target) {
      return true;
    }
    if (node->val > target) {
      return find(node->left, target);
    }
    return find(node->right, target);
  }
};

} // namespace bs

namespace tp {

// Time: O(N+M)
// Space: O(N+M)
class Solution {
public:
  static bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
    std::vector<int> vals1, vals2;
    dfs(root1, &vals1), dfs(root2, &vals2);

    for (int i = 0, j = vals2.size() - 1; i < std::ssize(vals1) && j >= 0;) {
      if (vals1[i] + vals2[j] == target) {
        return true;
      }
      if (vals1[i] + vals2[j] < target) {
        ++i;
      } else {
        --j;
      }
    }
    return false;
  }

private:
  static void dfs(TreeNode *node, std::vector<int> *vals) {
    if (!node) {
      return;
    }
    dfs(node->left, vals);
    vals->push_back(node->val);
    dfs(node->right, vals);
  }
};

} // namespace tp

namespace morris {

class BSTIterator {
public:
  BSTIterator(TreeNode *root, bool asc = true) : node(root), asc(asc) {}

  int next() {
    while (node) {
      if (get(node, asc)) {
        auto *pred = get(node, asc);
        while (get(pred, !asc) && get(pred, !asc) != node) {
          pred = get(pred, !asc);
        }

        if (get(pred, !asc)) {
          set(pred, nullptr, !asc);
          const auto val = node->val;
          node = get(node, !asc);
          return val;
        } else {
          set(pred, node, !asc);
          node = get(node, asc);
        }
      } else {
        const auto val = node->val;
        node = get(node, !asc);
        return val;
      }
    }
    throw;
  }

  bool hasNext() { return node; }

private:
  TreeNode *get(TreeNode *node, bool asc) {
    return asc ? node->left : node->right;
  }

  void set(TreeNode *node, TreeNode *child, bool asc) {
    asc ? node->left = child : node->right = child;
  }

  TreeNode *node;
  bool asc;
};

// Time: O(N+M)
// Space: O(1)
class Solution {
public:
  static bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
    auto it1 = BSTIterator(root1, true);
    auto it2 = BSTIterator(root2, false);

    bool find = false;
    for (int val1 = it1.next(), val2 = it2.next(); !find;) {
      if (val1 + val2 == target) {
        find = true;
      } else if (val1 + val2 < target) {
        if (!it1.hasNext()) {
          break;
        }
        val1 = it1.next();
      } else {
        if (!it2.hasNext()) {
          break;
        }
        val2 = it2.next();
      }
    }
    while (it1.hasNext()) {
      it1.next();
    }
    while (it2.hasNext()) {
      it2.next();
    }
    return find;
  }
};

} // namespace morris
