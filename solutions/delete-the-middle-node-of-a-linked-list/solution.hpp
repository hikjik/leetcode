#pragma once

#include <list_node.h>

/*
  2095. Delete the Middle Node of a Linked List
  https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
  Difficulty: Medium
  Tags: Linked List, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static ListNode *deleteMiddle(ListNode *head) {
    if (!head || !head->next) {
      return nullptr;
    }

    auto slow = head, fast = head->next->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto node = slow->next;
    slow->next = slow->next->next;
    delete node;

    return head;
  }
};
