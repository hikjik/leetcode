#pragma once

#include <array>
#include <string>

// Time: O(N!)
// Space: O(N)

class Solution {
public:
  static int numTilePossibilities(std::string tiles) {
    std::array<int, 26> counter{};
    for (auto c : tiles) {
      ++counter[c - 'A'];
    }
    return numTilePossibilities(tiles, &counter);
  }

private:
  static int numTilePossibilities(const std::string tiles,
                                  std::array<int, 26> *counter) {
    int ans = 0;
    for (auto &c : *counter) {
      if (c) {
        --c;
        ans += 1 + numTilePossibilities(tiles, counter);
        ++c;
      }
    }
    return ans;
  }
};
