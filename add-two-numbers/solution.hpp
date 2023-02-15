#pragma once

#include "list_node.hpp"

class Solution {
public:
  static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto dummy = new ListNode();

    int carry = 0;
    auto node = dummy;
    while (l1 || l2 || carry) {
      int k = carry;
      if (l1) {
        k += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        k += l2->val;
        l2 = l2->next;
      }

      carry = k / 10;
      node->next = new ListNode(k % 10);
      node = node->next;
    }

    auto head = dummy->next;
    delete dummy;
    return head;
  }
};
