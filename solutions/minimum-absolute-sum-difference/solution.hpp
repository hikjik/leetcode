#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static const int MODULO = 1e9 + 7;

  static int minAbsoluteSumDiff(const std::vector<int> &nums1,
                                const std::vector<int> &nums2) {
    std::vector<int> sorted(nums1);
    std::sort(sorted.begin(), sorted.end());

    long long distance = 0;
    int max_opt = 0;
    for (size_t i = 0; i < nums1.size(); ++i) {
      int diff = abs(nums1[i] - nums2[i]);
      distance += abs(nums1[i] - nums2[i]);
      int opt_diff = abs(closest(sorted, nums2[i]) - nums2[i]);
      max_opt = std::max(max_opt, diff - opt_diff);
    }

    return (distance - max_opt) % MODULO;
  }

private:
  static int closest(const std::vector<int> &arr, int x) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      if (x - arr[middle] <= arr[middle + 1] - x) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return arr[left];
  }
};
