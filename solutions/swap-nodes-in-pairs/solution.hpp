#pragma once

#include <list_node.h>

/*
  24. Swap Nodes in Pairs
  https://leetcode.com/problems/swap-nodes-in-pairs/
  Difficulty: Medium
  Tags: Linked List, Recursion
  Time:
  Space:
*/

class Solution {
public:
  static ListNode *swapPairs(ListNode *head) {
    auto dummy = ListNode(0, head);
    auto node = &dummy;
    while (head && head->next) {
      node->next = head->next;
      node = head;

      auto next_next = head->next->next;
      head->next->next = head;
      head = head->next = next_next;
    }
    return dummy.next;
  }
};
