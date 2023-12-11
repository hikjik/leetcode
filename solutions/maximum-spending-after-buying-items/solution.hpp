#pragma once

#include <queue>
#include <ranges>
#include <tuple>

#include <vector>

// Time: O(MNlogM)
// Space: O(M)

namespace sort {

// Time: O(MNlogNM)
// Space: O(NM)
class Solution {
public:
  static long long maxSpending(const std::vector<std::vector<int>> &values) {
    std::vector<int> nums;
    for (const auto &store : values) {
      for (auto val : store) {
        nums.push_back(val);
      }
    }
    std::ranges::sort(nums);
    long long ans = 0;
    for (long long day = 1; auto val : nums) {
      ans += day++ * val;
    }
    return ans;
  }
};

} // namespace sort

namespace heap {

// Time: O(MNlogM)
// Space: O(M)
class Solution {
public:
  static long long maxSpending(const std::vector<std::vector<int>> &values) {
    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>, std::greater<>>
        minHeap;
    for (int i = 0; i < std::ssize(values); ++i) {
      minHeap.push({values[i].back(), i, values[i].size() - 1});
    }

    long long ans = 0;
    for (long long day = 1; !minHeap.empty(); ++day) {
      const auto [value, i, j] = minHeap.top();
      minHeap.pop();

      ans += day * value;

      if (j) {
        minHeap.push({values[i][j - 1], i, j - 1});
      }
    }
    return ans;
  }
};

} // namespace heap
