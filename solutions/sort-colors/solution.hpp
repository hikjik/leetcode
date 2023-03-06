#pragma once

#include <vector>

class Solution {
public:
  static void sortColors(std::vector<int> &colors) {
    int num_colors = 3;
    std::vector<int> cnt(num_colors, 0);
    for (auto c : colors) {
      cnt[c]++;
    }

    for (int c = 0, i = 0; c < num_colors; ++c) {
      while (cnt[c]--) {
        colors[i++] = c;
      }
    }
  }
};
