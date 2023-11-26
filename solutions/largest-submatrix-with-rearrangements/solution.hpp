#pragma once

#include <ranges>
#include <vector>

// Time: O(MN)
// Space: O(N)

namespace sorting {

// Time: O(MNloN)
// Space: O(N)
class Solution {
public:
  static int largestSubmatrix(const std::vector<std::vector<int>> &matrix) {
    std::vector<int> heights(matrix.back().size());
    int ans = 0;
    for (const auto &row : matrix) {
      for (int i = 0; i < std::ssize(row); ++i) {
        heights[i] = row[i] ? heights[i] + 1 : 0;
      }

      auto sortedHeights = heights;
      std::ranges::sort(sortedHeights, std::greater{});

      for (int i = 0; auto h : sortedHeights) {
        ans = std::max(ans, ++i * h);
      }
    }
    return ans;
  }
};

} // namespace sorting

namespace no_sort {

// Time: O(MN)
// Space: O(N)
class Solution {
public:
  static int largestSubmatrix(const std::vector<std::vector<int>> &matrix) {
    std::vector<std::pair<int, int>> heights;
    int ans = 0;
    for (const auto &row : matrix) {
      std::vector<bool> seen(row.size());
      for (auto &[h, i] : heights) {
        h = row[i] ? h + 1 : 0;
        seen[i] = true;
      }

      heights.erase(
          std::remove_if(heights.begin(), heights.end(),
                         [](const auto &pair) { return !pair.first; }),
          heights.end());

      for (int i = 0; i < std::ssize(row); ++i) {
        if (!seen[i] && row[i]) {
          heights.push_back({1, i});
        }
      }

      for (int i = 0; auto [h, _] : heights) {
        ans = std::max(ans, ++i * h);
      }
    }
    return ans;
  }
};

} // namespace no_sort
