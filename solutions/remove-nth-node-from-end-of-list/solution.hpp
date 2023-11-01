#pragma once

#include <list_node.h>

/*
  19. Remove Nth Node From End of List
  https://leetcode.com/problems/remove-nth-node-from-end-of-list/
  Difficulty: Medium
  Tags: Linked List, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto dummy_node = ListNode(0, head);
    auto dummy = &dummy_node;

    auto before_delete = advance(dummy, listLength(head) - n);

    auto next = before_delete->next->next;
    delete before_delete->next;
    before_delete->next = next;

    return dummy->next;
  }

private:
  static int listLength(ListNode *head) {
    int length = 0;
    for (auto node = head; node; node = node->next) {
      ++length;
    }
    return length;
  }

  static ListNode *advance(ListNode *head, int n) {
    auto node = head;
    while (n--) {
      node = node->next;
    }
    return node;
  }
};
