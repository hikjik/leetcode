#pragma once

#include <ranges>
#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(N)

struct hashPair {
  template <class T, class U>
  std::size_t operator()(const std::pair<T, U> &p) const {
    return std::hash<T>()(p.first) ^ std::hash<U>()(p.second);
  }
};

class Solution {
public:
  static bool isReflected(const std::vector<std::vector<int>> &points) {
    const auto [leftmost, rightmost] = std::ranges::minmax(
        points, {}, [](const auto &point) { return point.front(); });
    const auto middleX = (leftmost[0] + rightmost[0]) / 2.0;

    std::unordered_set<std::pair<int, int>, hashPair> pointsSet;
    for (const auto &point : points) {
      pointsSet.insert({point[0], point[1]});
    }

    return std::ranges::all_of(points, [&](const auto &point) {
      return pointsSet.contains({2 * middleX - point[0], point[1]});
    });
  }
};
