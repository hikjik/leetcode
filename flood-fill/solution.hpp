#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>>
  floodFill(const std::vector<std::vector<int>> &image, int sr, int sc,
            int color) {
    if (image[sr][sc] == color) {
      return image;
    }

    std::vector<std::vector<int>> modified_image(image);
    int n = image.size();
    int m = image.back().size();

    std::vector<std::pair<int, int>> directions{
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    std::queue<std::pair<int, int>> queue;
    queue.emplace(sr, sc);
    while (!queue.empty()) {
      const auto &[r, c] = queue.front();
      queue.pop();
      modified_image[r][c] = color;

      for (auto direction : directions) {
        int n_sr = r + direction.first;
        int n_sc = c + direction.second;
        if (n_sr >= 0 && n_sr < n && n_sc >= 0 && n_sc < m &&
            modified_image[n_sr][n_sc] == image[sr][sc]) {
          queue.emplace(n_sr, n_sc);
        }
      }
    }

    return modified_image;
  }
};
