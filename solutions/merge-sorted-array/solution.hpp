#pragma once

#include <vector>

// Time: O(N+M)
// Space: O(1)

namespace linear {

// Time: O(N+M)
// Space: O(1)
class Solution {
public:
  static void merge(std::vector<int> &nums1, int m,
                    const std::vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1;
    for (int k = n + m - 1; k >= 0; --k) {
      if (j < 0 || i >= 0 && nums1[i] > nums2[j]) {
        nums1[k] = nums1[i--];
      } else {
        nums1[k] = nums2[j--];
      }
    }
  }
};

} // namespace linear

namespace stl {

// Time: O(N+M)
// Space: O(1)
class Solution {
public:
  static void merge(std::vector<int> &nums1, [[maybe_unused]] int m,
                    const std::vector<int> &nums2, int n) {
    std::merge(nums1.crbegin() + n, nums1.crend(), nums2.crbegin(),
               nums2.crend(), nums1.rbegin(), std::greater{});
  }
};

} // namespace stl
