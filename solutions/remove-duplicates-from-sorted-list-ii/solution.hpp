#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *deleteDuplicates(ListNode *head) {
    ListNode dummy(0, head);
    auto *prev = &dummy, *node = prev->next;
    while (node && node->next) {
      if (node->val == node->next->val) {
        const auto val = node->val;
        while (node && node->val == val) {
          prev->next = node->next;
          delete node;
          node = prev->next;
        }
      } else {
        prev = prev->next;
        node = node->next;
      }
    }
    return dummy.next;
  }
};
