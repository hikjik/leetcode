#pragma once

#include <vector>

// Time: O(MN)
// Space: O(MN)

class Solution {
public:
  static std::vector<std::vector<int>>
  resultGrid(const std::vector<std::vector<int>> &image, int threshold) {
    const int m = image.size(), n = image.back().size();
    std::vector cnt(m, std::vector<int>(n));
    std::vector avg(m, std::vector<int>(n));
    for (int i = 0; i + 2 < m; ++i) {
      for (int j = 0; j + 2 < n; ++j) {
        if (isRegion(i, j, image, threshold)) {
          int sum = 0;
          for (int x = i; x <= i + 2; ++x) {
            for (int y = j; y <= j + 2; ++y) {
              sum += image[x][y];
              ++cnt[x][y];
            }
          }
          for (int x = i; x <= i + 2; ++x) {
            for (int y = j; y <= j + 2; ++y) {
              avg[x][y] += sum / 9;
            }
          }
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        avg[i][j] = cnt[i][j] ? avg[i][j] / cnt[i][j] : image[i][j];
      }
    }
    return avg;
  }

private:
  static bool isRegion(int i, int j, const std::vector<std::vector<int>> &image,
                       int threshold) {
    for (int x = i; x <= i + 2; ++x) {
      for (int y = j; y <= j + 2; ++y) {
        if (x > i && std::abs(image[x][y] - image[x - 1][y]) > threshold ||
            y > j && std::abs(image[x][y] - image[x][y - 1]) > threshold) {
          return false;
        }
      }
    }
    return true;
  }
};
