#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int compress(std::vector<char> &chars) {
    const int n = chars.size();
    int size = 0;
    for (int i = 0; i < n;) {
      int len = 1;
      while (i + len < n && chars[i] == chars[i + len]) {
        ++len;
      }
      chars[size++] = chars[i];
      i += len;
      if (len > 1) {
        for (auto d : std::to_string(len)) {
          chars[size++] = d;
        }
      }
    }
    return size;
  }
};
