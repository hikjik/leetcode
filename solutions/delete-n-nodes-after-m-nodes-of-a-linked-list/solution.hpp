#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *deleteNodes(ListNode *head, int m, int n) {
    for (auto *node = head; node;) {
      node = advance(node, m - 1);
      if (node) {
        node->next = advance(node, n + 1);
        node = node->next;
      }
    }
    return head;
  }

private:
  static ListNode *advance(ListNode *node, int k) {
    while (node && k--) {
      node = node->next;
    }
    return node;
  }
};
