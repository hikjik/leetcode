#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::string subStrHash(std::string s, int power, int modulo, int k,
                                int hashValue) {
    const int n = s.size();

    long long pk = 1;
    for (int i = 0; i < k; ++i) {
      pk = pk * power % modulo;
    }

    long long hash = 0;
    int pos = 0;
    for (int i = n - 1; i >= 0; --i) {
      hash = (hash * power + s[i] - 'a' + 1) % modulo;
      if (i + k < n) {
        hash = (hash - (s[i + k] - 'a' + 1) * pk % modulo + modulo) % modulo;
      }
      if (i + k <= n && hash == hashValue) {
        pos = i;
      }
    }
    return s.substr(pos, k);
  }
};
