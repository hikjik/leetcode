#pragma once

#include <list_node.h>

/*
  206. Reverse Linked List
  https://leetcode.com/problems/reverse-linked-list/
  Difficulty: Easy
  Tags: Linked List, Recursion
  Time:
  Space:
*/

class Solution {
public:
  static ListNode *reverseList(ListNode *head) {
    ListNode *reversed_list_head = nullptr;

    auto node = head;
    while (node) {
      auto next = node->next;

      node->next = reversed_list_head;
      reversed_list_head = node;

      node = next;
    }

    return reversed_list_head;
  }
};
