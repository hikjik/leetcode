#pragma once

#include <list_node.h>

class Solution {
public:
  static ListNode *removeElements(ListNode *head, int val) {
    auto dummy_node = ListNode(0, head);
    auto dummy = &dummy_node;

    auto node = dummy;
    while (node && node->next) {
      if (node->next->val == val) {
        auto next = node->next->next;
        delete node->next;
        node->next = next;
      } else {
        node = node->next;
      }
    }

    return dummy->next;
  }
};
