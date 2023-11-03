#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode dummy(0, head);

    auto *before = &dummy;
    for (int i = 0; i < left - 1; ++i) {
      before = before->next;
    }

    auto *node = before->next;
    for (int i = left; i < right; ++i) {
      auto *next = node->next;
      node->next = next->next;
      next->next = before->next;
      before->next = next;
    }

    return dummy.next;
  }
};
