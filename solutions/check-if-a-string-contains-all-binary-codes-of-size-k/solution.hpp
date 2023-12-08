#pragma once

#include <string>
#include <unordered_set>

// Time: O(N)
// Space: O(2^K)

class Solution {
public:
  static bool hasAllCodes(std::string s, int k) {
    std::vector<bool> seen(1 << k);
    int cnt = 0;
    for (int code = 0, i = 0; i < std::ssize(s); ++i) {
      code = (code << 1) + s[i] - '0';
      code = code & (~(1 << k));
      if (i >= k - 1) {
        cnt += !seen[code];
        seen[code] = true;
      }
    }
    return cnt == 1 << k;
  }
};
