#pragma once

#include <list_node.h>

class Solution {
public:
  static ListNode *reverseBetween(ListNode *head, int left, int right) {
    auto dummy_node = ListNode(0, head);
    auto dummy = &dummy_node;

    auto before_reversed_part = dummy;
    for (int i = 1; i < left; ++i) {
      before_reversed_part = before_reversed_part->next;
    }

    ListNode *reversed_list_head = nullptr;
    auto node = before_reversed_part->next;
    for (int i = left; i <= right; ++i) {
      auto next = node->next;
      node->next = reversed_list_head;
      reversed_list_head = node;
      node = next;
    }

    before_reversed_part->next->next = node;
    before_reversed_part->next = reversed_list_head;

    return dummy->next;
  }
};
