#pragma once

#include <array>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> findEvenNumbers(const std::vector<int> &digits) {
    std::array<int, 10> counter{};
    for (auto d : digits) {
      ++counter[d];
    }

    std::vector<int> ans;
    for (int a = 1; a < 10; ++a) {
      for (int b = 0; b < 10; ++b) {
        for (int c = 0; c < 10; c += 2) {
          if (counter[a] && counter[b] > (a == b) &&
              counter[c] > (a == c) + (b == c)) {
            ans.push_back(a * 100 + b * 10 + c);
          }
        }
      }
    }
    return ans;
  }
};
