#pragma once

#include <bitset>
#include <string>
#include <vector>

// N is the length of array garbage
// K is the maximum length of garbage[i]
// Time: O(NK)
// Space: O(1)

class Solution {
public:
  static int garbageCollection(const std::vector<std::string> &garbage,
                               const std::vector<int> &travel) {
    int ans = 0;
    std::bitset<3> types;
    for (int i = garbage.size() - 1; i >= 0; --i) {
      for (auto c : garbage[i]) {
        types.set(c == 'P' ? 0 : c == 'G' ? 1 : 2);
      }
      ans += garbage[i].size();
      if (i) {
        ans += travel[i - 1] * types.count();
      }
    }
    return ans;
  }
};
