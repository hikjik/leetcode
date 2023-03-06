#pragma once

#include <list_node.h>

class Solution {
public:
  static ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    auto dummy = ListNode(0, head);
    auto slow = &dummy, fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto left = head;
    auto right = slow->next;
    slow->next = nullptr;

    return mergeLists(sortList(left), sortList(right));
  }

private:
  static ListNode *mergeLists(ListNode *left, ListNode *right) {
    auto dummy_merged = ListNode();

    auto node = &dummy_merged;
    while (left || right) {
      if (!right || left && left->val < right->val) {
        auto next = left->next;
        left->next = nullptr;
        node->next = left;
        left = next;
      } else {
        auto next = right->next;
        right->next = nullptr;
        node->next = right;
        right = next;
      }
      node = node->next;
    }

    return dummy_merged.next;
  }
};
