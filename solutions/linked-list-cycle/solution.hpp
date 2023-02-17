#pragma once

#include <list_node.h>

class Solution {
public:
  static bool hasCycle(ListNode *head) {
    auto small_step = head;
    auto big_step = head;
    do {
      if (!big_step || !big_step->next) {
        return false;
      }
      big_step = big_step->next->next;
      small_step = small_step->next;
    } while (small_step != big_step);
    return true;
  }
};
