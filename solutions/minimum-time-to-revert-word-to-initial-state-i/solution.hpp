#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int minimumTimeToInitialState(std::string word, int k) {
    const int n = word.size();
    const auto z = zFunction(word);

    int ans = 1;
    for (; ans * k < n; ++ans) {
      if (z[ans * k] == n - k * ans) {
        break;
      }
    }
    return ans;
  }

private:
  static std::vector<int> zFunction(const std::string &s) {
    const int n = s.size();
    std::vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
      if (i < r) {
        z[i] = std::min(r - i, z[i - l]);
      }
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
        ++z[i];
      }
      if (i + z[i] > r) {
        l = i;
        r = i + z[i];
      }
    }
    return z;
  }
};
