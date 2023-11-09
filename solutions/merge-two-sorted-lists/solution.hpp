#pragma once

#include <list_node.h>

// Time: O(N+M)
// Space: O(1)

namespace recursive {

// Time: O(N+M)
// Space: O(N+M)
class Solution {
public:
  static ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1 || !list2) {
      return list1 ? list1 : list2;
    }
    if (list2->val < list1->val) {
      std::swap(list1, list2);
    }
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
  }
};

} // namespace recursive

namespace iterative {

// Time: O(N+M)
// Space: O(1)
class Solution {
public:
  static ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
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

} // namespace iterative
