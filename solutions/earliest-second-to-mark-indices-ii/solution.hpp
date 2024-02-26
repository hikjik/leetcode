#pragma once

#include <numeric>
#include <queue>
#include <ranges>
#include <vector>

// Time: O((NlogN+M)logM)
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
    std::vector<int> first(nums.size(), -1);
    for (int i = m - 1; i >= 0; --i) {
      if (nums[changeIndices[i] - 1]) {
        first[changeIndices[i] - 1] = i;
      }
    }

    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
    int ops = 0;
    for (int i = m - 1; i >= 0; --i) {
      if (i == first[changeIndices[i] - 1]) {
        minHeap.push(nums[changeIndices[i] - 1]);
        if (ops) {
          --ops;
        } else {
          ++ops;
          minHeap.pop();
        }
      } else {
        ++ops;
      }
    }

    long long sum = std::reduce(nums.begin(), nums.end(), 0LL) + nums.size() -
                    minHeap.size();
    while (!minHeap.empty()) {
      sum -= minHeap.top();
      minHeap.pop();
    }
    return sum <= ops;
  }
};
