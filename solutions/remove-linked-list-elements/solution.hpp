#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy(0, head);

    auto *node = &dummy;
    while (node && node->next) {
      if (node->next->val == val) {
        auto *next = node->next->next;
        delete node->next;
        node->next = next;
      } else {
        node = node->next;
      }
    }

    return dummy.next;
  }
};
