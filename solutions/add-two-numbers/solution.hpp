#pragma once

#include <list_node.h>

/*
  2. Add Two Numbers
  https://leetcode.com/problems/add-two-numbers/
  Difficulty: Medium
  Tags: Linked List, Math, Recursion
  Time:
  Space:
*/

class Solution {
public:
  static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy;
    auto *node = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
      if (l1) {
        carry += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        carry += l2->val;
        l2 = l2->next;
      }
      node->next = new ListNode(carry % 10);
      carry /= 10;
      node = node->next;
    }
    return dummy.next;
  }
};
