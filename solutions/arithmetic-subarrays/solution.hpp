#pragma once

#include <ranges>
#include <span>
#include <unordered_set>
#include <vector>

// Time: O(MN)
// Space: O(N)

namespace sorting {

// Time: O(MNlogN)
// Space: O(N)
class Solution {
public:
  static std::vector<bool>
  checkArithmeticSubarrays(const std::vector<int> &nums,
                           const std::vector<int> &l,
                           const std::vector<int> &r) {
    std::vector<bool> ans(l.size());
    for (int i = 0; i < std::ssize(l); ++i) {
      ans[i] = isArithmetic({nums.begin() + l[i], nums.begin() + r[i] + 1});
    }
    return ans;
  }

private:
  static bool isArithmetic(std::vector<int> nums) {
    std::ranges::sort(nums);
    for (int i = 2; i < std::ssize(nums); ++i) {
      if (nums[i] - nums[i - 1] != nums[1] - nums[0]) {
        return false;
      }
    }
    return true;
  }
};

} // namespace sorting

namespace hash_table {

// Time: O(MN)
// Space: O(N)
class Solution {
public:
  static std::vector<bool>
  checkArithmeticSubarrays(const std::vector<int> &nums,
                           const std::vector<int> &l,
                           const std::vector<int> &r) {
    std::vector<bool> ans(l.size());
    for (int i = 0; i < std::ssize(l); ++i) {
      ans[i] = isArithmetic({nums.begin() + l[i], nums.begin() + r[i] + 1});
    }
    return ans;
  }

private:
  static bool isArithmetic(std::span<const int> nums) {
    const auto [min, max] = std::ranges::minmax(nums);
    if (min == max) {
      return true;
    }
    if ((max - min) % (nums.size() - 1)) {
      return false;
    }
    const auto diff = (max - min) / (nums.size() - 1);

    std::unordered_set<int> set;
    for (auto num : nums) {
      if ((num - min) % diff || set.contains(num)) {
        return false;
      }
      set.insert(num);
    }
    return true;
  }
};

} // namespace hash_table
