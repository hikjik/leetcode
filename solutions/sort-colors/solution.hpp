#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

namespace iterators {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static void sortColors(std::vector<int> &nums) {
    auto left = nums.begin(), right = nums.end();
    for (auto it = nums.begin(); it != right; ++it) {
      if (*it == 0) {
        std::iter_swap(left++, it);
      } else if (*it == 2) {
        std::iter_swap(it--, --right);
      }
    }
  }
};

} // namespace iterators

namespace counting_sort {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static void sortColors(std::vector<int> &nums) {
    std::vector<int> counter(3);
    for (auto a : nums) {
      ++counter[a];
    }
    for (int i = 0, k = 0; i < std::ssize(counter); ++i) {
      for (int j = 0; j < counter[i]; ++j) {
        nums[k++] = i;
      }
    }
  }
};

} // namespace counting_sort
