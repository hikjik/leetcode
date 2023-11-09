#pragma once

#include <list_node.h>

#include <climits>

// Time: O(N^2)
// Space: O(1)

class Solution {
public:
  static ListNode *insertionSortList(ListNode *head) {
    ListNode dummy(INT_MIN, head);
    for (auto *prev = &dummy, *curr = head; curr; curr = prev->next) {
      if (prev->val <= curr->val) {
        prev = curr;
        continue;
      }

      auto *before_insert = &dummy;
      while (before_insert->next->val < curr->val) {
        before_insert = before_insert->next;
      }

      prev->next = curr->next;
      curr->next = before_insert->next;
      before_insert->next = curr;
    }
    return dummy.next;
  }
};
