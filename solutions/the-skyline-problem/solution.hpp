#pragma once

#include <cmath>
#include <queue>
#include <ranges>
#include <set>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

namespace multiset {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static std::vector<std::vector<int>>
  getSkyline(const std::vector<std::vector<int>> &buildings) {
    std::vector<std::pair<int, int>> edges;
    for (const auto &b : buildings) {
      edges.push_back({b[0], -b[2]});
      edges.push_back({b[1], b[2]});
    }
    std::ranges::sort(edges);

    std::multiset<int> queue{0};
    std::vector<std::vector<int>> ans;
    for (int height = 0; auto [x, y] : edges) {
      if (y < 0) {
        queue.insert(-y);
      } else {
        queue.erase(queue.find(y));
      }
      if (height != *queue.rbegin()) {
        height = *queue.rbegin();
        ans.push_back({x, height});
      }
    }
    return ans;
  }
};

} // namespace multiset

namespace pq {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static std::vector<std::vector<int>>
  getSkyline(const std::vector<std::vector<int>> &buildings) {
    std::vector<std::tuple<int, int, int>> edges;
    for (const auto &b : buildings) {
      edges.push_back({b[0], -b[2], b[1]});
      edges.push_back({b[1], b[2], b[1]});
    }
    std::ranges::sort(edges);

    std::priority_queue<std::pair<int, int>> queue;
    std::vector<std::vector<int>> ans;
    for (auto [x1, y, x2] : edges) {
      if (y < 0) {
        queue.push({-y, x2});
      }
      while (!queue.empty() && queue.top().second <= x1) {
        queue.pop();
      }
      const auto height = queue.empty() ? 0 : queue.top().first;
      if (ans.empty() || ans.back().back() != height) {
        ans.push_back({x1, height});
      }
    }
    return ans;
  }
};

} // namespace pq
