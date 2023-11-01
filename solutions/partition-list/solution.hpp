#pragma once

#include <list_node.h>

/*
  86. Partition List
  https://leetcode.com/problems/partition-list/
  Difficulty: Medium
  Tags: Linked List, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static ListNode *partition(ListNode *head, int x) {
    ListNode before(0, head), after(0, nullptr);
    auto small = &before, big = &after;
    while (small->next) {
      if (small->next->val >= x) {
        auto next = small->next;
        small->next = small->next->next;
        next->next = nullptr;

        big->next = next;
        big = big->next;
      } else {
        small = small->next;
      }
    }
    small->next = after.next;
    return before.next;
  }
};
