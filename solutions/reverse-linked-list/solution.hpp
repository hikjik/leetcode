#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *reverseList(ListNode *head) {
    ListNode *reversed = nullptr;
    for (auto *node = head; node;) {
      auto *next = node->next;
      node->next = reversed;
      reversed = node;
      node = next;
    }
    return reversed;
  }
};
