#pragma once

#include <ranges>
#include <vector>

class Solution {
public:
  static std::vector<int> maxSubsequence(const std::vector<int> &nums, int k) {
    const auto kth = getKthLargestElement(nums, k);
    int equal = k - std::ranges::count_if(nums, [&](int a) { return a > kth; });
    std::vector<int> ans(k);
    std::ranges::copy_if(nums, ans.begin(), [&](int a) {
      return a > kth || a == kth && equal-- > 0;
    });
    return ans;
  }

private:
  static int getKthLargestElement(std::vector<int> nums, int k) {
    std::ranges::nth_element(nums, nums.begin() + k - 1, std::greater{});
    return nums[k - 1];
  }
};
