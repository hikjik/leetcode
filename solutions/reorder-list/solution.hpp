#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static void reorderList(ListNode *head) {
    combine(head, reverse(splitInMiddle(head)));
  }

private:
  static void combine(ListNode *first, ListNode *second) {
    while (second) {
      auto *next = first->next;
      first->next = second;
      first = second;
      second = next;
    }
  }

  static ListNode *splitInMiddle(ListNode *head) {
    ListNode dummy(0, head);

    auto *slow = &dummy, *fast = slow;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto *middle = slow->next;
    slow->next = nullptr;
    return middle;
  }

  static ListNode *reverse(ListNode *head) {
    ListNode *reversed = nullptr;
    for (auto *node = head; node;) {
      auto *next = node->next;
      node->next = reversed;
      reversed = node;
      node = next;
    }
    return reversed;
  }
};
