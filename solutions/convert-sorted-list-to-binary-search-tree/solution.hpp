#pragma once

#include <list_node.h>
#include <tree_node.h>

// Time:  O(N)
// Space: O(logN)

class Solution {
public:
  static TreeNode *sortedListToBST(ListNode *head) {
    return buildTree(0, getLength(head) - 1, head);
  }

private:
  static TreeNode *buildTree(int left, int right, ListNode *&node) {
    if (left > right) {
      return nullptr;
    }
    const auto middle = left + (right - left) / 2;

    auto *left_subtree = buildTree(left, middle - 1, node);
    const auto root_value = node->val;
    node = node->next;
    auto *right_subtree = buildTree(middle + 1, right, node);

    return new TreeNode(root_value, left_subtree, right_subtree);
  }

  static int getLength(ListNode *head) {
    int length = 0;
    for (auto *node = head; node; node = node->next) {
      ++length;
    }
    return length;
  }
};
