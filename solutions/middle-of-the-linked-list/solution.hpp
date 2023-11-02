#pragma once

#include <list_node.h>

// Time:
// Space:

class Solution {
public:
  static ListNode *middleNode(ListNode *head) {
    int half = size(head) / 2;
    auto node = head;
    while (half--) {
      node = node->next;
    }
    return node;
  }

  static size_t size(ListNode *head) {
    size_t length = 0;
    for (auto node = head; node; node = node->next) {
      length++;
    }
    return length;
  }
};
