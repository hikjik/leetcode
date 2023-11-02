#pragma once

#include <list_node.h>

// Time:
// Space:

class Solution {
public:
  static int pairSum(ListNode *head) {
    auto half = reverse(secondHalf(head));
    int max_sum = 0;
    for (auto l = head, r = half; r; l = l->next, r = r->next) {
      max_sum = std::max(max_sum, l->val + r->val);
    }
    reverse(half);
    return max_sum;
  }

private:
  static ListNode *secondHalf(ListNode *head) {
    auto fast = head, slow = head;
    while (fast) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  static ListNode *reverse(ListNode *node) {
    ListNode *reversed = nullptr;
    while (node) {
      auto next = node->next;
      node->next = reversed;
      reversed = node;
      node = next;
    }
    return reversed;
  }
};
