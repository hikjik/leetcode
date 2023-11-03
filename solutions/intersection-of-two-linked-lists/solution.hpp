#pragma once

#include <list_node.h>

// Time:
// Space:

class Solution {
public:
  static ListNode *getIntersectionNode(ListNode *head_a, ListNode *head_b) {
    auto a = head_a, b = head_b;
    while (a != b) {
      a = a ? a->next : head_b;
      b = b ? b->next : head_a;
    }
    return a;
  }
};
