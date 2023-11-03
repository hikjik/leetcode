#pragma once

#include <vector>

// Time: O(KC(N,K))
// Space: O(K)

class Solution {
public:
  static std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<int> combination;
    std::vector<std::vector<int>> combinations;
    combine(n, k, 1, &combination, &combinations);
    return combinations;
  }

private:
  static void combine(int n, int k, int s, std::vector<int> *combination,
                      std::vector<std::vector<int>> *combinations) {
    if (k == 0) {
      combinations->push_back(*combination);
      return;
    }
    for (int i = s; i <= n; ++i) {
      combination->push_back(i);
      combine(n, k - 1, i + 1, combination, combinations);
      combination->pop_back();
    }
  }
};
