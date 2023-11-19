#pragma once

#include <algorithm>
#include <bit>
#include <vector>

// N is the size of the array heights
// M is the number of queries
// Time: O((N+M)logN)
// Space: O(NlogN)

class RangeMaxQuery {
public:
  RangeMaxQuery(const std::vector<int> &nums)
      : sparse_table(std::bit_width(nums.size()),
                     std::vector<int>(nums.size())) {
    sparse_table[0] = nums;
    for (auto i = 1u; i < sparse_table.size(); ++i) {
      for (auto j = 0u; j + std::rotl(1u, i) <= nums.size(); ++j) {
        sparse_table[i][j] =
            std::max(sparse_table[i - 1][j],
                     sparse_table[i - 1][j + std::rotl(1u, i - 1)]);
      }
    }
  }

  int getMax(unsigned a, unsigned b) const {
    const auto length = b - a + 1;
    const auto i = std::bit_width(length) - 1;
    const auto k = std::bit_floor(length);
    return std::max(sparse_table[i][a], sparse_table[i][b - k + 1]);
  }

private:
  std::vector<std::vector<int>> sparse_table;
};

class Solution {
public:
  static std::vector<int>
  leftmostBuildingQueries(const std::vector<int> &heights,
                          const std::vector<std::vector<int>> &queries) {
    const int n = heights.size();
    const RangeMaxQuery rmq(heights);

    std::vector<int> ans;
    for (const auto &query : queries) {
      const auto [a, b] = std::ranges::minmax(query);
      if (a == b || heights[a] < heights[b]) {
        ans.push_back(b);
        continue;
      }

      if (rmq.getMax(b, n - 1) <= heights[a]) {
        ans.push_back(-1);
        continue;
      }

      auto l = b, r = n - 1;
      while (l < r) {
        const auto m = l + (r - l) / 2;
        rmq.getMax(l, m) > heights[a] ? r = m : l = m + 1;
      }
      ans.push_back(l);
    }
    return ans;
  }
};
