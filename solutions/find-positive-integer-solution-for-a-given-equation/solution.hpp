#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class CustomFunction {
public:
  virtual int f(int x, int y) = 0;
};

namespace brute_force {

// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  static std::vector<std::vector<int>>
  findSolution(CustomFunction &customfunction, int z) {
    std::vector<std::vector<int>> ans;
    for (int x = 1; x <= 1000; ++x) {
      for (int y = 1; y <= 1000; ++y) {
        if (customfunction.f(x, y) == z) {
          ans.push_back({x, y});
        }
      }
    }
    return ans;
  }
};

} // namespace brute_force

namespace binary_search {

// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
  static std::vector<std::vector<int>>
  findSolution(CustomFunction &customfunction, int z) {
    std::vector<std::vector<int>> ans;
    for (int x = 1; x <= 1000; ++x) {
      int l = 1, r = 1000;
      while (l < r) {
        const int m = l + (r - l + 1) / 2;
        customfunction.f(x, m) > z ? r = m - 1 : l = m;
      }
      if (customfunction.f(x, l) == z) {
        ans.push_back({x, l});
      }
    }
    return ans;
  }
};

} // namespace binary_search

namespace linear {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static std::vector<std::vector<int>>
  findSolution(CustomFunction &customfunction, int z) {
    std::vector<std::vector<int>> ans;
    for (int y = 1000, x = 1; x <= 1000; ++x) {
      while (y > 1 && customfunction.f(x, y) > z) {
        --y;
      }
      if (customfunction.f(x, y) == z) {
        ans.push_back({x, y});
      }
    }
    return ans;
  }
};

} // namespace linear
