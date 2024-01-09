#pragma once

#include <vector>

// Time: O(N^(1.5))
// Space: O(logN)

class Solution {
public:
  static std::vector<std::vector<int>> getFactors(int n) {
    std::vector<std::vector<int>> combinations;
    std::vector<int> combination;
    getFactors(n, 2, &combination, &combinations);
    return combinations;
  }

private:
  static void getFactors(int n, int d, std::vector<int> *combination,
                         std::vector<std::vector<int>> *combinations) {
    for (int i = d; i * i <= n; ++i) {
      if (n % i == 0) {
        combination->push_back(i);
        combination->push_back(n / i);
        combinations->push_back(*combination);
        combination->pop_back();
        getFactors(n / i, i, combination, combinations);
        combination->pop_back();
      }
    }
  }
};
