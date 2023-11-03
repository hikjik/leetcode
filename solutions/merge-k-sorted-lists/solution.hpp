#pragma once

#include <list_node.h>

#include <queue>
#include <vector>

// Time: O(NKlogK) for K linked lists each of size N
// Space: O(K)

class Solution {
public:
  static ListNode *mergeKLists(std::vector<ListNode *> lists) {
    auto greater = [](ListNode *lhs, ListNode *rhs) {
      return lhs->val > rhs->val;
    };
    std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(greater)>
        queue(greater);
    for (auto *list : lists) {
      if (list) {
        queue.emplace(list);
      }
    }

    ListNode dummy;
    for (auto *node = &dummy; !queue.empty(); node = node->next) {
      auto *list = queue.top();
      queue.pop();

      node->next = list;

      if (list->next) {
        queue.emplace(list->next);
      }
    }
    return dummy.next;
  }
};
