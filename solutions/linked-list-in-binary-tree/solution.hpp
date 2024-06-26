#pragma once

#include <list_node.h>
#include <tree_node.h>

// Time:
// Space:

class Solution {
public:
  static bool isSubPath(ListNode *head, TreeNode *root) {
    if (!root) {
      return false;
    }
    return checkPath(head, root) || isSubPath(head, root->left) ||
           isSubPath(head, root->right);
  }

private:
  static bool checkPath(ListNode *head, TreeNode *root) {
    if (!head) {
      return true;
    }
    if (!root) {
      return false;
    }
    return head->val == root->val && (checkPath(head->next, root->left) ||
                                      checkPath(head->next, root->right));
  }
};
