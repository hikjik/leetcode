#pragma once

#include <unordered_set>
#include <vector>

#include <list_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int numComponents(ListNode *head, const std::vector<int> &nums) {
    std::unordered_set<int> set(nums.begin(), nums.end());
    int ans = 0;
    for (auto *node = head; node; node = node->next) {
      ans += set.contains(node->val) &&
             (!node->next || !set.contains(node->next->val));
    }
    return ans;
  }
};
