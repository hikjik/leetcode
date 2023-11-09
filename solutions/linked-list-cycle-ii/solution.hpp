#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *detectCycle(ListNode *head) {
    auto *slow = head;
    auto *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
