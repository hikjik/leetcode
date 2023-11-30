#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *mergeNodes(ListNode *head) {
    for (auto *curr = head->next; curr; curr = curr->next) {
      auto *node = curr->next;
      for (; node->val; node = node->next) {
        curr->val += node->val;
      }
      curr->next = node->next;
    }
    return head->next;
  }
};
