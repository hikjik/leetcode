#pragma once

#include <list_node.h>

/*
  83. Remove Duplicates from Sorted List
  https://leetcode.com/problems/remove-duplicates-from-sorted-list/
  Difficulty: Easy
  Tags: Linked List
  Time:
  Space:
*/

class Solution {
public:
  static ListNode *deleteDuplicates(ListNode *head) {
    auto node = head;
    while (node && node->next) {
      if (node->val == node->next->val) {
        auto next = node->next->next;
        delete node->next;
        node->next = next;
      } else {
        node = node->next;
      }
    }
    return head;
  }
};
