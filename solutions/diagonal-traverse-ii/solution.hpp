#pragma once

#include <numeric>
#include <queue>
#include <ranges>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(1)

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
    std::queue<int> queue{{0}};
    for (int group = 0; !queue.empty(); ++group) {
      for (int sz = queue.size(); sz; --sz) {
        const auto j = queue.front();
        const auto i = group - j;
        queue.pop();

        ans.push_back(nums[i][j]);

        if (!j && i + 1 < std::ssize(nums)) {
          queue.push(j);
        }
        if (j + 1 < std::ssize(nums[i])) {
          queue.push(j + 1);
        }
      }
    }
    return ans;
  }
};

} // namespace bfs

namespace optimized {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static std::vector<int>
  findDiagonalOrder(const std::vector<std::vector<int>> &nums) {
    int n = 0;
    for (const auto &row : nums) {
      n += row.size();
    }

    std::vector<int> ans(n);
    int start = 0, end = 1;
    for (int group = 0; start < n; ++group) {
      int size = 0;
      for (int k = start; k < end; ++k) {
        const auto j = ans[k];
        const auto i = group - j;

        ans[k] = nums[i][j];

        if (!j && i + 1 < std::ssize(nums)) {
          ans[end + size++] = j;
        }
        if (j + 1 < std::ssize(nums[i])) {
          ans[end + size++] = j + 1;
        }
      }
      start = end;
      end += size;
    }
    return ans;
  }
};

} // namespace optimized
