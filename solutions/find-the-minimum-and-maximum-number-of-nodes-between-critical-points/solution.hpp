#pragma once

#include <list_node.h>

#include <algorithm>
#include <climits>
#include <vector>

/*
  2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
  https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
  Difficulty: Medium
  Tags: Linked List
  Time:
  Space:
*/

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
