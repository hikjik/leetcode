#pragma once

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
private:
  static const int kMod = 1e9 + 7;

  static int naive(const std::vector<int> &nums, int n, int left, int right) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        queue;

    for (int i = 0; i < n; ++i) {
      queue.emplace(nums[i], i + 1);
    }

    int sum = 0;
    for (int i = 0; i < right; ++i) {
      const auto [num, index] = queue.top();
      queue.pop();

      if (i + 1 >= left) {
        sum += num;
        sum %= kMod;
      }

      if (index < n) {
        queue.emplace(num + nums[index], index + 1);
      }
    }
    return sum;
  }

public:
  static int rangeSum(const std::vector<int> &nums, int n, int left,
                      int right) {
    return naive(nums, n, left, right);
  }
};
