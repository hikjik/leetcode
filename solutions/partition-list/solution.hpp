#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *partition(ListNode *head, int x) {
    ListNode dummy_before, dummy_after;

    auto *before = &dummy_before, *after = &dummy_after;
    for (auto *node = head; node; node = node->next) {
      if (node->val < x) {
        before = before->next = node;
      } else {
        after = after->next = node;
      }
    }

    after->next = nullptr;
    before->next = dummy_after.next;
    return dummy_before.next;
  }
};
