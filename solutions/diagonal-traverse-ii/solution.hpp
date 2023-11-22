#pragma once

#include <queue>
#include <ranges>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(√N)

namespace hash_table {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int>
  findDiagonalOrder(const std::vector<std::vector<int>> &nums) {
    std::unordered_map<int, std::vector<int>> groups;
    for (int i = nums.size() - 1; i >= 0; --i) {
      for (int j = 0; j < std::ssize(nums[i]); ++j) {
        groups[i + j].push_back(nums[i][j]);
      }
    }

    std::vector<int> ans;
    for (int i = 0; groups.contains(i); ++i) {
      std::ranges::copy(groups[i], std::back_inserter(ans));
    }
    return ans;
  }
};

} // namespace hash_table

namespace bfs {

// Time: O(N)
// Space: O(√N)
class Solution {
public:
  static std::vector<int>
  findDiagonalOrder(const std::vector<std::vector<int>> &nums) {
    std::vector<int> ans;
    std::queue<std::pair<int, int>> queue{{{0, 0}}};
    while (!queue.empty()) {
      const auto [i, j] = queue.front();
      queue.pop();

      ans.push_back(nums[i][j]);

      if (!j && i + 1 < std::ssize(nums)) {
        queue.push({i + 1, j});
      }
      if (j + 1 < std::ssize(nums[i])) {
        queue.push({i, j + 1});
      }
    }
    return ans;
  }
};

} // namespace bfs
