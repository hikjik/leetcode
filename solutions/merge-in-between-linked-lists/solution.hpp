#pragma once

#include <list_node.h>

// Time: O(N+M)
// Space: O(1)

class Solution {
public:
  static ListNode *mergeInBetween(ListNode *list1, int a, int b,
                                  ListNode *list2) {
    auto *beforeA = advance(list1, a - 1);
    auto *afterB = advance(beforeA, b - a + 2);
    auto *tail2 = getTail(list2);

    beforeA->next = list2;
    tail2->next = afterB;

    return list1;
  }

private:
  static ListNode *advance(ListNode *node, int a) {
    while (a--) {
      node = node->next;
    }
    return node;
  }

  static ListNode *getTail(ListNode *node) {
    while (node->next) {
      node = node->next;
    }
    return node;
  }
};
