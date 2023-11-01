#pragma once

#include <list_node.h>

/*
  1721. Swapping Nodes in a Linked List
  https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
  Difficulty: Medium
  Tags: Linked List, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static ListNode *swapNodes(ListNode *head, int k) {
    auto left = head;
    while (--k) {
      left = left->next;
    }

    auto right = head;
    for (auto node = left->next; node; node = node->next) {
      right = right->next;
    }

    std::swap(left->val, right->val);

    return head;
  }
};
