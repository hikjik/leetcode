#pragma once

#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace sorting {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int
  maximumElementAfterDecrementingAndRearranging(std::vector<int> arr) {
    std::ranges::sort(arr);
    int ans = 0;
    for (auto a : arr) {
      ans = std::min(a, ans + 1);
    }
    return ans;
  }
};

} // namespace sorting

namespace counting {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int
  maximumElementAfterDecrementingAndRearranging(std::vector<int> arr) {
    const int n = arr.size();

    std::vector<int> counter(n + 1);
    for (auto a : arr) {
      ++counter[std::min(a, n)];
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans = std::min(i, ans + counter[i]);
    }
    return ans;
  }
};

} // namespace counting
