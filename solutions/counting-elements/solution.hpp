#pragma once

#include <ranges>
#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int countElements(const std::vector<int> &arr) {
    std::unordered_set<int> s(arr.begin(), arr.end());
    return std::ranges::count_if(arr, [&](int a) { return s.contains(a + 1); });
  }
};
