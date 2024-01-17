#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static bool uniqueOccurrences(const std::vector<int> &arr) {
    std::unordered_map<int, int> counter;
    for (auto num : arr) {
      ++counter[num];
    }

    std::unordered_set<int> set;
    for (const auto &[_, cnt] : counter) {
      if (!set.insert(cnt).second) {
        return false;
      }
    }
    return true;
  }
};
