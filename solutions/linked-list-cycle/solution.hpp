#pragma once

#include <list_node.h>

/*
  141. Linked List Cycle
  https://leetcode.com/problems/linked-list-cycle/
  Difficulty: Easy
  Tags: Hash Table, Linked List, Two Pointers
  Time:
  Space:
*/

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
