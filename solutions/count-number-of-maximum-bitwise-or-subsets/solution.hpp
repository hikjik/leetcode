#pragma once

#include <numeric>
#include <span>
#include <unordered_map>
#include <vector>

// Time: O(2^N)
// Space: O(2^N)

namespace backtracking {

// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
  static int countMaxOrSubsets(const std::vector<int> &nums) {
    const int maxOr = std::reduce(nums.begin(), nums.end(), 0, std::bit_or{});
    return countMaxOrSubsets(std::span{nums}, 0, maxOr);
  }

private:
  static int countMaxOrSubsets(std::span<const int> nums, int curr, int maxOr) {
    if (nums.empty()) {
      return curr == maxOr;
    }
    return countMaxOrSubsets(nums.subspan(1), curr, maxOr) +
           countMaxOrSubsets(nums.subspan(1), nums[0] | curr, maxOr);
  }
};

} // namespace backtracking

namespace dp {

// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
  static int countMaxOrSubsets(const std::vector<int> &nums) {
    std::unordered_map<int, int> counter{{0, 1}};
    for (auto num : nums) {
      for (const auto &[val, cnt] : std::unordered_map<int, int>(counter)) {
        counter[val | num] += cnt;
      }
    }

    const int maxOr = std::reduce(nums.begin(), nums.end(), 0, std::bit_or{});
    return counter[maxOr];
  }
};

} // namespace dp
