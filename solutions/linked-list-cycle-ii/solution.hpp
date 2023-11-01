#pragma once

#include <list_node.h>

/*
  142. Linked List Cycle II
  https://leetcode.com/problems/linked-list-cycle-ii/
  Difficulty: Medium
  Tags: Hash Table, Linked List, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static ListNode *detectCycle(ListNode *head) {
    auto small_step = head;
    auto big_step = head;
    do {
      if (!big_step || !big_step->next) {
        return nullptr;
      }
      big_step = big_step->next->next;
      small_step = small_step->next;
    } while (small_step != big_step);

    auto cycle_start = head;
    while (cycle_start != small_step) {
      cycle_start = cycle_start->next;
      small_step = small_step->next;
    }

    return cycle_start;
  }
};
