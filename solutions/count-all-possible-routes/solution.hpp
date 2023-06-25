#pragma once

#include <cmath>
#include <vector>

class Solution {
public:
  static int countRoutes(const std::vector<int> &locations, size_t start,
                         size_t finish, int fuel) {
    std::vector<std::vector<int>> dp(locations.size(),
                                     std::vector<int>(fuel + 1, -1));
    return countRoutes(locations, start, finish, fuel, &dp);
  }

private:
  static const int kMod = 1e9 + 7;

  static int countRoutes(const std::vector<int> &locations, size_t start,
                         size_t finish, int fuel,
                         std::vector<std::vector<int>> *dp) {
    if (fuel < 0) {
      return 0;
    }

    auto &cnt = (*dp)[start][fuel];
    if (cnt != -1) {
      return cnt;
    }

    cnt = start == finish ? 1 : 0;

    for (size_t i = 0; i < locations.size(); ++i) {
      if (i == start) {
        continue;
      }

      cnt += countRoutes(locations, i, finish,
                         fuel - std::abs(locations[i] - locations[start]), dp);
      cnt %= kMod;
    }

    return cnt;
  }
};
