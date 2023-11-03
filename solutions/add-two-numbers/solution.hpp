#pragma once

#include <list_node.h>

// Time: O(max(M, N))
// Space: O(1)

namespace recursion {

// Time: O(max(M, N))
// Space: O(max(M, N))
// Recursion Approach
class Solution {
public:
  static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry = 0) {
    if (!l1 && !l2 && !carry) {
      return nullptr;
    }
    if (l1) {
      carry += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      carry += l2->val;
      l2 = l2->next;
    }
    return new ListNode(carry % 10, addTwoNumbers(l1, l2, carry / 10));
  }
};

} // namespace recursion

namespace iterative {

// Time: O(max(M, N))
// Space: O(1)
// Iterative Approach
class Solution {
public:
  static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy_head;
    auto *node = &dummy_head;
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

    return dummy_head.next;
  }
};

} // namespace iterative
