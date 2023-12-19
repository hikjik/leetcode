#pragma once

#include <ranges>
#include <vector>

// Time: O(K(N+M)^2)
// Space: O(N+M)

class Solution {
public:
  static std::vector<int> maxNumber(const std::vector<int> &nums1,
                                    const std::vector<int> &nums2, int k) {
    const int m = nums1.size(), n = nums2.size();
    std::vector<int> ans;
    for (int i = std::max(0, k - n); i <= std::min(k, m); ++i) {
      ans = std::max(ans, merge(maxNumber(nums1, i), maxNumber(nums2, k - i)));
    }
    return ans;
  }

private:
  static std::vector<int> maxNumber(const std::vector<int> &nums, int k) {
    std::vector<int> max;
    for (int drop = nums.size() - k; auto a : nums) {
      while (!max.empty() && max.back() < a && drop-- > 0) {
        max.pop_back();
      }
      max.push_back(a);
    }
    max.resize(k);
    return max;
  }

  static std::vector<int> merge(const std::vector<int> &nums1,
                                const std::vector<int> &nums2) {
    std::vector<int> nums;
    auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
    while (it1 != nums1.cend() || it2 != nums2.cend()) {
      if (std::lexicographical_compare(it1, nums1.cend(), it2, nums2.cend())) {
        nums.push_back(*it2++);
      } else {
        nums.push_back(*it1++);
      }
    }
    return nums;
  }
};
