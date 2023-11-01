#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>

/*
  1584. Min Cost to Connect All Points
  https://leetcode.com/problems/min-cost-to-connect-all-points/
  Difficulty: Medium
  Tags: Array, Union Find, Graph, Minimum Spanning Tree
  Time:
  Space:
*/

class Solution {
public:
  static int minCostConnectPoints(std::vector<std::vector<int>> points) {
    std::vector<int> distances(points.size(), INT_MAX);
    int cost = 0;
    for (size_t i = 0; i + 1 < points.size(); ++i) {
      for (size_t j = i + 1; j < points.size(); ++j) {
        const auto distance = manhattanDistance(points[i], points[j]);
        distances[j] = std::min(distances[j], distance);

        if (distances[j] < distances[i + 1]) {
          std::swap(points[j], points[i + 1]);
          std::swap(distances[j], distances[i + 1]);
        }
      }
      cost += distances[i + 1];
    }
    return cost;
  }

private:
  static int manhattanDistance(const std::vector<int> &lhs,
                               const std::vector<int> &rhs) {
    return std::abs(lhs[0] - rhs[0]) + std::abs(lhs[1] - rhs[1]);
  }
};
