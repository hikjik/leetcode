#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto dummy = ListNode(0, head);

    auto *fast = &dummy;
    while (n--) {
      fast = fast->next;
    }

    auto *slow = &dummy;
    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }

    auto *next = slow->next->next;
    delete slow->next;
    slow->next = next;

    return dummy.next;
  }
};
