#pragma once

#include <ranges>
#include <unordered_set>
#include <vector>

// Time: O(M^2+N^2)
// Space: O(M^2)

class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int maximizeSquareArea(int m, int n, std::vector<int> hFences,
                                std::vector<int> vFences) {
    hFences.push_back(1), hFences.push_back(m);
    std::ranges::sort(hFences);

    std::unordered_set<int> seen;
    for (int i = 0; i < std::ssize(hFences); ++i) {
      for (int j = 0; j < i; ++j) {
        seen.insert(hFences[i] - hFences[j]);
      }
    }

    vFences.push_back(1), vFences.push_back(n);
    std::ranges::sort(vFences);
    int size = -1;
    for (int i = 0; i < std::ssize(vFences); ++i) {
      for (int j = 0; j < i; ++j) {
        if (seen.contains(vFences[i] - vFences[j])) {
          size = std::max(size, vFences[i] - vFences[j]);
        }
      }
    }

    return size == -1 ? -1 : 1LL * size * size % kMod;
  }
};
