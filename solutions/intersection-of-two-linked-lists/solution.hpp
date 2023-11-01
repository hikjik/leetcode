#pragma once

#include <list_node.h>

/*
  160. Intersection of Two Linked Lists
  https://leetcode.com/problems/intersection-of-two-linked-lists/
  Difficulty: Easy
  Tags: Hash Table, Linked List, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static ListNode *getIntersectionNode(ListNode *head_a, ListNode *head_b) {
    auto a = head_a, b = head_b;
    while (a != b) {
      a = a ? a->next : head_b;
      b = b ? b->next : head_a;
    }
    return a;
  }
};
