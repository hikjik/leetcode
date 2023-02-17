#pragma once

#include <list_node.h>

class Solution {
public:
  static ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    auto dummy_node = ListNode();
    auto dummy = &dummy_node;

    auto node = dummy;
    while (list1 || list2) {
      if (!list1 || (list2 && list2->val < list1->val)) {
        node->next = new ListNode(list2->val);
        list2 = list2->next;
      } else {
        node->next = new ListNode(list1->val);
        list1 = list1->next;
      }
      node = node->next;
    }

    return dummy->next;
  }
};