#pragma once

#include <list_node.h>

/*
  143. Reorder List
  https://leetcode.com/problems/reorder-list/
  Difficulty: Medium
  Tags: Linked List, Two Pointers, Stack, Recursion
  Time:
  Space:
*/

class Solution {
public:
  static void reorderList(ListNode *head) {
    mergeLists(head, reverseList(splitInMiddle(head)));
  }

private:
  static void mergeLists(ListNode *first, ListNode *second) {
    while (second) {
      auto next = first->next;
      first->next = second;
      first = second;
      second = next;
    }
  }

  static ListNode *splitInMiddle(ListNode *head) {
    auto dummy = ListNode(0, head);

    auto slow = &dummy, fast = slow;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto middle = slow->next;
    slow->next = nullptr;
    return middle;
  }

  static ListNode *reverseList(ListNode *head) {
    ListNode *reversed = nullptr;

    auto node = head;
    while (node) {
      auto next = node->next;
      node->next = reversed;
      reversed = node;
      node = next;
    }

    return reversed;
  }
};
