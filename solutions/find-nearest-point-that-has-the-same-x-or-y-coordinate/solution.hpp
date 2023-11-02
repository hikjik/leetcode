#pragma once

#include <limits>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int nearestValidPoint(int x, int y,
                               const std::vector<std::vector<int>> &points) {
    int position = -1;
    int min_distance = std::numeric_limits<int>::max();
    for (size_t i = 0; i < points.size(); ++i) {
      if (is_valid(x, y, points[i])) {
        const auto distance = manhattan_distance(x, y, points[i]);
        if (distance < min_distance) {
          min_distance = distance;
          position = i;
        }
      }
    }
    return position;
  }

private:
  static bool is_valid(int x, int y, const std::vector<int> &point) {
    return point[0] == x || point[1] == y;
  }

  static int manhattan_distance(int x, int y, const std::vector<int> &point) {
    return abs(x - point[0]) + abs(y - point[1]);
  }
};
