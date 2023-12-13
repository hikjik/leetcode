#pragma once

#include <vector>

// X is the time to compute getPower
// Time: O(NlogN + NX)
// Space: O(N)
// Notes: [Collatz conjecture](https://w.wiki/329)

class Solution {
public:
  static int getKth(int lo, int hi, int k) {
    std::vector<std::pair<int, int>> pows;
    for (int i = lo; i <= hi; ++i) {
      pows.push_back({getPower(i), i});
    }
    std::nth_element(pows.begin(), pows.begin() + k - 1, pows.end());
    return pows[k - 1].second;
  }

private:
  static int getPower(int x) {
    int ans = 0;
    while (x != 1) {
      x = x & 1 ? 3 * x + 1 : x / 2;
      ++ans;
    }
    return ans;
  }
};
