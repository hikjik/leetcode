#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> partitionLabels(std::string s) {
    int n = s.size();
    std::vector<int> last(128);
    for (int i = 0; i < n; ++i) {
      last[s[i]] = i;
    }

    std::vector<int> parts;
    int start = 0, end = 0;
    for (int i = 0; i < n; ++i) {
      end = std::max(end, last[s[i]]);
      if (end == i) {
        parts.push_back(end - start + 1);
        start = i + 1;
      }
    }
    return parts;
  }
};
