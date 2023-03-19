#pragma once

#include <list_node.h>

class Solution {
public:
  static ListNode *reverseKGroup(ListNode *head, int k) {
    auto dummy = ListNode(0, head);
    auto prev = &dummy;
    for (int i = length(head) / k; i > 0; --i) {
      auto curr = prev->next;
      for (int j = 0; j < k - 1; ++j) {
        auto next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
      }
      prev = curr;
    }
    return dummy.next;
  }

private:
  static int length(ListNode *node) {
    int length = 0;
    while (node) {
      node = node->next;
      length++;
    }
    return length;
  }
};
