#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *deleteDuplicates(ListNode *head) {
    auto *node = head;
    while (node && node->next) {
      if (node->val == node->next->val) {
        auto *next = node->next->next;
        delete node->next;
        node->next = next;
      } else {
        node = node->next;
      }
    }
    return head;
  }
};
