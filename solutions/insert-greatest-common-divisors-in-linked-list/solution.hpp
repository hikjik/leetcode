#pragma once

#include <list_node.h>

#include <numeric>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *insertGreatestCommonDivisors(ListNode *head) {
    for (auto *node = head; node->next; node = node->next->next) {
      node->next =
          new ListNode(std::gcd(node->val, node->next->val), node->next);
    }
    return head;
  }
};
