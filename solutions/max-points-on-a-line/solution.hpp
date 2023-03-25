#pragma once

#include <cmath>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static int maxPoints(const std::vector<std::vector<int>> &points) {
    return efficient(points);
  }

private:
  static int efficient(const std::vector<std::vector<int>> &points) {
    int max_count = 1;
    for (size_t i = 0; i < points.size(); i++) {
      std::unordered_map<double, int> counter;
      for (size_t j = 0; j < points.size(); j++) {
        if (i == j) {
          continue;
        }
        const auto angle = std::atan2(points[j][1] - points[i][1],
                                      points[j][0] - points[i][0]);
        counter[angle]++;
      }
      for (const auto &cnt : counter) {
        max_count = std::max(max_count, cnt.second + 1);
      }
    }
    return max_count;
  }

  static int naive(const std::vector<std::vector<int>> &points) {
    int max_count = 1;
    for (size_t i = 0; i < points.size(); ++i) {
      for (size_t j = i + 1; j < points.size(); ++j) {
        const auto dx = points[i][0] - points[j][0];
        const auto dy = points[i][1] - points[j][1];
        int cnt = 0;
        for (const auto &point : points) {
          if ((point[0] - points[i][0]) * dy ==
              (point[1] - points[i][1]) * dx) {
            cnt++;
          }
        }
        max_count = std::max(max_count, cnt);
      }
    }
    return max_count;
  }
};
