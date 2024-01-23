#pragma once

#include <functional>
#include <ranges>
#include <string>
#include <vector>

// Time: O(2^N)
// Space: O(N)

class Solution {
public:
  static int maxLength(const std::vector<std::string> &arr) {
    std::vector<unsigned> masks;
    for (const auto &s : arr) {
      const auto mask = getMask(s);
      if (mask) {
        masks.push_back(mask);
      }
    }
    return maxLength(0, 0, masks);
  }

private:
  static int maxLength(int i, unsigned mask,
                       const std::vector<unsigned> &masks) {
    if (i == std::ssize(masks)) {
      return 0;
    }
    const auto skip = maxLength(i + 1, mask, masks);
    if (mask & masks[i]) {
      return skip;
    }
    const auto pick =
        std::popcount(masks[i]) + maxLength(i + 1, mask | masks[i], masks);
    return std::max(skip, pick);
  }

  static unsigned getMask(const std::string &s) {
    unsigned mask = 0;
    for (auto c : s) {
      if (mask & (1 << (c - 'a'))) {
        return 0;
      }
      mask |= (1 << (c - 'a'));
    }
    return mask;
  }
};
