#pragma once

#include <memory>
#include <string>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::string smallestFromLeaf(TreeNode *root) {
    std::string ans;
    dfs(root, "", ans);
    return ans;
  }

  static void dfs(TreeNode *root, std::string &&path, std::string &ans) {
    if (!root) {
      return;
    }

    path.push_back(root->val + 'a');
    if (!root->left && !root->right) {
      if (ans.empty() ||
          std::lexicographical_compare(path.rbegin(), path.rend(), ans.begin(),
                                       ans.end())) {
        ans.assign(path.rbegin(), path.rend());
      }
    }

    dfs(root->left, std::move(path), ans);
    dfs(root->right, std::move(path), ans);
    path.pop_back();
  }
};
