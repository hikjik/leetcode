#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *plusOne(ListNode *head) {
    auto sentinel = new ListNode(0, head);

    ListNode *notNine = sentinel;
    for (auto *node = head; node; node = node->next) {
      if (node->val != 9) {
        notNine = node;
      }
    }

    ++notNine->val;
    for (auto *node = notNine->next; node; node = node->next) {
      node->val = 0;
    }

    if (sentinel->val) {
      return sentinel;
    }
    delete sentinel;
    return head;
  }
};
