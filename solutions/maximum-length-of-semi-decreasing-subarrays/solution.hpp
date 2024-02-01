#pragma once

#include <numeric>
#include <ranges>
#include <stack>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace sorting {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int maxSubarrayLength(const std::vector<int> &nums) {
    std::vector<int> indexes(nums.size());
    std::iota(indexes.begin(), indexes.end(), 0);
    std::ranges::sort(indexes, [&](int i, int j) {
      return std::tie(nums[i], i) < std::tie(nums[j], j);
    });

    int ans = 0;
    for (int max = -1; auto index : indexes) {
      ans = std::max(ans, max - index + 1);
      max = std::max(max, index);
    }
    return ans;
  }
};

} // namespace sorting

namespace stack {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int maxSubarrayLength(const std::vector<int> &nums) {
    std::stack<int> stack;
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (stack.empty() || nums[stack.top()] < nums[i]) {
        stack.push(i);
      }
    }

    int ans = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
      while (!stack.empty() && nums[stack.top()] > nums[i]) {
        ans = std::max(ans, i - stack.top() + 1);
        stack.pop();
      }
    }
    return ans;
  }
};

} // namespace stack
