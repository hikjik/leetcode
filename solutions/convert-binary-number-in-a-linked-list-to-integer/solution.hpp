#pragma once

#include <list_node.h>

/*
  1290. Convert Binary Number in a Linked List to Integer
  https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
  Difficulty: Easy
  Tags: Linked List, Math
  Time:
  Space:
*/

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