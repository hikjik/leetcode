#pragma once

#include <list_node.h>

// Time: O(N+M)
// Space: O(1)

class Solution {
public:
  static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto *a = headA, *b = headB;
    while (a != b) {
      a = a ? a->next : headB;
      b = b ? b->next : headA;
    }
    return a;
  }
};
