#pragma once

#include <numeric>
#include <ranges>
#include <string>

// Time: O(N)
// Space: O(N)

namespace brute_force {

// Time: O(N!)
// Space: O(N)
class Solution {
public:
  static std::string smallestNumber(std::string pattern) {
    std::string ans(pattern.size() + 1, '0');
    std::iota(ans.begin(), ans.end(), '1');

    do {
      if (checkCondition(ans, pattern)) {
        return ans;
      }
    } while (std::ranges::next_permutation(ans).found);

    throw;
  }

private:
  static bool checkCondition(const std::string &pattern, const std::string &p) {
    for (int i = 0; i < std::ssize(p); ++i) {
      if (p[i] == 'I' != pattern[i] < pattern[i + 1]) {
        return false;
      }
    }
    return true;
  }
};

} // namespace brute_force

namespace stack {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::string smallestNumber(std::string pattern) {
    const int n = pattern.size();
    std::string ans;
    std::string stack;
    for (int i = 0; i <= n; ++i) {
      stack.push_back('1' + i);
      if (i == n || pattern[i] == 'I') {
        while (!stack.empty()) {
          ans.push_back(stack.back());
          stack.pop_back();
        }
      }
    }
    return ans;
  }
};

} // namespace stack
