#pragma once

#include <list_node.h>

class Solution {
public:
  static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto dummy_node = ListNode();
    auto dummy = &dummy_node;

    int carry = 0;
    auto node = dummy;
    while (l1 || l2 || carry) {
      int sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }

      carry = sum / 10;
      node->next = new ListNode(sum % 10);
      node = node->next;
    }

    return dummy->next;
  }
};
