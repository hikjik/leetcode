#pragma once

#include <string>
#include <unordered_set>

// Time: O(nk^n)
// Space: O(k^n)
// Notes: [de Bruijn sequence](https://w.wiki/8aUi)

class Solution {
public:
  static std::string crackSafe(int n, int k) {
    std::unordered_map<std::string, int> set;
    std::string ans(n - 1, '0');
    for (int i = 0; i < std::pow(k, n); ++i) {
      ans += '0' + ++set[ans.substr(i, n - 1)] % k;
    }
    return ans;
  }
};
