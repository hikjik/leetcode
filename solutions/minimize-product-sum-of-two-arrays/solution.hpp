#pragma once

#include <array>
#include <numeric>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(M), M = max(nums)

namespace sorting {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int minProductSum(std::vector<int> nums1, std::vector<int> nums2) {
    std::ranges::sort(nums1);
    std::ranges::sort(nums2);
    return std::inner_product(nums1.cbegin(), nums1.cend(), nums2.crbegin(), 0);
  }
};

} // namespace sorting

namespace counting {

// Time: O(N)
// Space: O(M), M = max(nums)
class Solution {
public:
  static constexpr int kMax = 100;

  static int minProductSum(const std::vector<int> &nums1,
                           const std::vector<int> &nums2) {
    std::array<int, kMax + 1> cnt1{}, cnt2{};
    for (auto num : nums1) {
      ++cnt1[num];
    }
    for (auto num : nums2) {
      ++cnt2[num];
    }

    int ans = 0;
    int i = 0, j = kMax;
    while (i <= kMax && j >= 0) {
      while (i <= kMax && !cnt1[i]) {
        ++i;
      }
      while (j >= 0 && !cnt2[j]) {
        --j;
      }
      if (i <= kMax && j >= 0) {
        const auto f = std::min(cnt1[i], cnt2[j]);
        cnt1[i] -= f, cnt2[j] -= f;
        ans += f * i * j;
      }
    }
    return ans;
  }
};

} // namespace counting
