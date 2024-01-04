#pragma once

#include <vector>

// Time: O(N+L1+L2)
// Space O(L1+L2)

class SparseVector {
public:
  // Time: O(N)
  // Space O(L1)
  explicit SparseVector(const std::vector<int> &nums) {
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (nums[i]) {
        data.push_back({i, nums[i]});
      }
    }
  }

  // Time: O(L1 + L2)
  // Space O(1)
  int dotProduct(const SparseVector &vec) {
    int prod = 0;
    size_t i = 0, j = 0;
    while (i < data.size() && j < vec.data.size()) {
      if (data[i].first == vec.data[j].first) {
        prod += data[i++].second * vec.data[j++].second;
      } else {
        data[i].first < vec.data[j].first ? ++i : ++j;
      }
    }
    return prod;
  }

private:
  std::vector<std::pair<int, int>> data;
};
