#pragma once

#include <list_node.h>

// Time:
// Space:

class Solution {
public:
  static ListNode *swapNodes(ListNode *head, int k) {
    auto left = head;
    while (--k) {
      left = left->next;
    }

    auto right = head;
    for (auto node = left->next; node; node = node->next) {
      right = right->next;
    }

    std::swap(left->val, right->val);

    return head;
  }
};
