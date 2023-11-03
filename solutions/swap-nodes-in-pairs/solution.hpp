#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *swapPairs(ListNode *head) {
    auto dummy = ListNode(0, head);
    auto node = &dummy;
    while (head && head->next) {
      node->next = head->next;
      node = head;

      auto next_next = head->next->next;
      head->next->next = head;
      head = head->next = next_next;
    }
    return dummy.next;
  }
};
