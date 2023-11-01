#pragma once

#include <list_node.h>

/*
  328. Odd Even Linked List
  https://leetcode.com/problems/odd-even-linked-list/
  Difficulty: Medium
  Tags: Linked List
  Time:
  Space:
*/

class Solution {
public:
  static ListNode *oddEvenList(ListNode *head) {
    auto dummy_odds = ListNode(), dummy_evens = ListNode();
    auto odds = &dummy_odds, evens = &dummy_evens;

    for (int i = 1; head; ++i) {
      auto next = head->next;
      head->next = nullptr;
      if (i & 1) {
        odds->next = head;
        odds = odds->next;
      } else {
        evens->next = head;
        evens = evens->next;
      }
      head = next;
    }
    odds->next = dummy_evens.next;
    return dummy_odds.next;
  }
};
