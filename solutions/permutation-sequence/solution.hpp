#pragma once

#include <numeric>
#include <ranges>
#include <string>
#include <vector>

// Time: O(N^2)
// Space: O(N)

namespace naive {

// Time: O(N!)
// Space: O(N)
class Solution {
public:
  static std::string getPermutation(int n, int k) {
    std::string s(n, '0');
    std::iota(s.begin(), s.end(), '1');
    while (--k) {
      std::ranges::next_permutation(s);
    }
    return s;
  }
};

} // namespace naive

namespace efficient {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static std::string getPermutation(int n, int k) {
    std::vector<int> factorials(n, 1);
    for (int i = 1; i < n; ++i) {
      factorials[i] = i * factorials[i - 1];
    }

    std::vector<int> indexes(n);
    for (int i = n - 1, idx = k - 1; i >= 0; --i) {
      indexes[n - 1 - i] = idx / factorials[i];
      idx %= factorials[i];
    }

    std::string digits = "123456789";
    std::string ans;
    for (auto i : indexes) {
      ans += digits[i];
      digits.erase(digits.begin() + i);
    }
    return ans;
  }
};

} // namespace efficient
