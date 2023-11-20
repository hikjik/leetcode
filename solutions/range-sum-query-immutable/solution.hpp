#pragma once

#include <numeric>
#include <vector>

// Time: O(N+M)
// Space: O(N)

class NumArray {
public:
  NumArray(const std::vector<int> &nums) : prefix_sum(nums.size() + 1, 0) {
    std::partial_sum(nums.begin(), nums.end(), prefix_sum.begin() + 1);
  }

  int sumRange(int left, int right) {
    return prefix_sum[right + 1] - prefix_sum[left];
  }

private:
  std::vector<int> prefix_sum;
};
