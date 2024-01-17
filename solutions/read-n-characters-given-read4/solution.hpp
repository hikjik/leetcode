#pragma once

#include <cstring>
#include <functional>

// Time: O(N)
// Space: O(1)

std::function<int(char *)> read4;

class Solution {
public:
  static int read(char *buf, int n) {
    int ans = 0;
    while (ans < n) {
      char tmp[4];
      const auto m = std::min(read4(tmp), n - ans);
      if (!m) {
        break;
      }
      std::strncpy(buf + ans, tmp, m);
      ans += m;
    }
    return ans;
  }
};
