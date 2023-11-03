#pragma once

#include <list_node.h>
#include <tree_node.h>

// Time:
// Space:

class Solution {
public:
  static TreeNode *sortedListToBST(ListNode *head) {
    return buildTree(0, lengthOfList(head) - 1, head);
  }

private:
  static TreeNode *buildTree(int left, int right, ListNode *&node) {
    if (left > right) {
      return nullptr;
    }
    const auto middle = left + (right - left) / 2;

    auto left_tree = buildTree(left, middle - 1, node);
    auto root = new TreeNode(node->val, left_tree, nullptr);
    node = node->next;
    root->right = buildTree(middle + 1, right, node);
    return root;
  }

  static int lengthOfList(ListNode *head) {
    int length = 0;
    for (auto node = head; node; node = node->next) {
      length++;
    }
    return length;
  }
};
