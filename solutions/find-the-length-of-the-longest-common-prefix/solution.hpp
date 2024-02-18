#pragma once

#include <string>
#include <unordered_set>
#include <vector>

// Time: O(N+M)
// Space: O(N)

class Solution {
public:
  static int longestCommonPrefix(const std::vector<int> &nums1,
                                 const std::vector<int> &nums2) {
    std::unordered_set<int> set;
    for (auto num : nums1) {
      for (int x = num; x; x /= 10) {
        set.insert(x);
      }
    }

    int ans = 0;
    for (auto num : nums2) {
      for (int x = num; x > ans; x /= 10) {
        if (set.contains(x)) {
          ans = x;
        }
      }
    }
    return ans == 0 ? 0 : std::to_string(ans).size();
  }
};
