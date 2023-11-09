#pragma once

#include <list_node.h>

// Time:
// Space:

namespace recursive {

// Time: O(NlogN)
// Space: O(logN)
class Solution {
public:
  static ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    auto *slow = head;
    auto *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto *left = head;
    auto *right = slow->next;
    slow->next = nullptr;

    return mergeLists(sortList(left), sortList(right));
  }

private:
  static ListNode *mergeLists(ListNode *list1, ListNode *list2) {
    ListNode dummy;
    for (auto *node = &dummy; list1 || list2; node = node->next) {
      if (!list1 || !list2) {
        node->next = list1 ? list1 : list2;
        break;
      }
      if (list2->val < list1->val) {
        std::swap(list1, list2);
      }
      node->next = list1;
      list1 = list1->next;
    }
    return dummy.next;
  }
};

} // namespace recursive
