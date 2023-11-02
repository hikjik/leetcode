#pragma once

#include <list_node.h>

// Time:
// Space:

class Solution {
public:
  static ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next || !k) {
      return head;
    }

    auto tail = head;
    int length = 1;
    while (tail->next) {
      tail = tail->next;
      length++;
    }
    tail->next = head;

    k = length - k % length;
    while (k--) {
      tail = tail->next;
    }
    auto rotated_head = tail->next;
    tail->next = nullptr;
    return rotated_head;
  }
};