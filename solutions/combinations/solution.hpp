#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> combinations;
    std::vector<int> combination;
    combine(n, k, 1, &combinations, &combination);
    return combinations;
  }

private:
  static void combine(int n, int k, int start,
                      std::vector<std::vector<int>> *combinations,
                      std::vector<int> *combination) {
    int size = combination->size();
    if (size == k) {
      combinations->push_back(*combination);
      return;
    }

    for (int i = start; i <= n; ++i) {
      combination->push_back(i);
      combine(n, k, i + 1, combinations, combination);
      combination->pop_back();
    }
  }
};
