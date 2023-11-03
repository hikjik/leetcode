#pragma once

#include <list_node.h>

// Time:
// Space:

class Solution {
public:
  static int getDecimalValue(ListNode *head) {
    int value = 0;
    for (auto node = head; node; node = node->next) {
      value *= 2;
      value += node->val;
    }
    return value;
  }
};