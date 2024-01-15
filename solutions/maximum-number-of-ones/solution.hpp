#pragma once

#include <numeric>
#include <ranges>
#include <vector>

// S = sideLength
// Time: O(S^2)
// Space: O(S^2)

class Solution {
public:
  static int maximumNumberOfOnes(int width, int height, int sideLength,
                                 int maxOnes) {
    std::vector<int> freq;
    for (int i = 0; i < sideLength; ++i) {
      for (int j = 0; j < sideLength; ++j) {
        const auto h = (height - i + sideLength - 1) / sideLength;
        const auto w = (width - j + sideLength - 1) / sideLength;
        freq.push_back(h * w);
      }
    }
    std::ranges::nth_element(freq, freq.begin() + maxOnes, std::greater{});
    return std::accumulate(freq.begin(), freq.begin() + maxOnes, 0);
  }
};
