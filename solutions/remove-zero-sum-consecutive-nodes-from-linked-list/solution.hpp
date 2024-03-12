#pragma once

#include <unordered_map>

#include <list_node.h>

namespace ps {

// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  static ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode dummy(0, head);
    for (auto *start = &dummy; start; start = start->next) {
      int sum = 0;
      for (auto *end = start->next; end; end = end->next) {
        sum += end->val;
        if (!sum) {
          start->next = end->next;
        }
      }
    }
    return dummy.next;
  }
};

} // namespace ps

namespace ht {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode dummy(0, head);
    std::unordered_map<int, ListNode *> map;
    int sum = 0;
    for (auto *curr = &dummy; curr; curr = curr->next) {
      sum += curr->val;
      if (map.contains(sum)) {
        auto *node = std::exchange(map[sum]->next, curr->next);
        for (auto s = sum + node->val; s != sum; s += node->val) {
          map.erase(s);
          node = node->next;
        }
      } else {
        map[sum] = curr;
      }
    }
    return dummy.next;
  }
};

} // namespace ht
