#pragma once

#include <vector>

// Time: O((M+N)logM)
// Space: O(N)

class Solution {
public:
  static int
  earliestSecondToMarkIndices(const std::vector<int> &nums,
                              const std::vector<int> &changeIndices) {
    const int m = changeIndices.size();
    int left = 1, right = m + 1;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      canMark(nums, changeIndices, middle) ? right = middle : left = middle + 1;
    }
    return left == m + 1 ? -1 : left;
  }

private:
  static bool canMark(const std::vector<int> &nums,
                      const std::vector<int> &changeIndices, int m) {
    std::vector<int> last(nums.size(), -1);
    for (int i = 0; i < m; ++i) {
      last[changeIndices[i] - 1] = i;
    }

    if (std::ranges::any_of(last, [](int a) { return a == -1; })) {
      return false;
    }

    int ops = 0;
    for (int i = 0; i < m; ++i) {
      if (i == last[changeIndices[i] - 1]) {
        if (ops < nums[changeIndices[i] - 1]) {
          return false;
        }
        ops -= nums[changeIndices[i] - 1];
      } else {
        ++ops;
      }
    }
    return true;
  }
};
