#pragma once

#include <list_node.h>

#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    int first = 0, last = 0;
    int min_dist = INT_MAX;
    auto prev = head, curr = head->next;
    for (int index = 1; curr && curr->next; ++index) {
      if (prev->val < curr->val && curr->val > curr->next->val ||
          prev->val > curr->val && curr->val < curr->next->val) {
        if (!first) {
          first = index;
        } else {
          min_dist = std::min(min_dist, index - last);
        }
        last = index;
      }
      curr = curr->next, prev = prev->next;
    }

    if (last == first) {
      return {-1, -1};
    }
    return {min_dist, last - first};
  }
};
