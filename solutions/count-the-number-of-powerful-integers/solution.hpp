#pragma once

#include <cmath>
#include <string>

// Time: O(logN)
// Space: O(logN)

class Solution {
public:
  static long long numberOfPowerfulInt(long long start, long long finish,
                                       int limit, std::string s) {
    return numberOfPowerfulIntAtMost(std::to_string(finish), s, limit) -
           numberOfPowerfulIntAtMost(std::to_string(start - 1), s, limit);
  }

  static long long numberOfPowerfulIntAtMost(std::string num, std::string s,
                                             int limit) {
    if (num.size() < s.size()) {
      return 0;
    }
    if (num.size() == s.size()) {
      return num >= s;
    }

    const int m = num.size() - s.size();
    long long ans = 0;
    for (int i = 0; i < m; i++) {
      const auto d = num[i] - '0';
      if (limit < d) {
        return ans += std::pow(limit + 1, m - i);
      }
      ans += d * std::pow(limit + 1, m - i - 1);
    }
    return ans += num.substr(m) >= s;
  }
};
