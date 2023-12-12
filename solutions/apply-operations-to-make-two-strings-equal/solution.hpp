#pragma once

#include <span>
#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

namespace memo {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int minOperations(std::string s1, std::string s2, int x) {
    std::vector<int> idx;
    for (int i = 0; i < std::ssize(s1); ++i) {
      if (s1[i] != s2[i]) {
        idx.push_back(i);
      }
    }

    if (idx.size() & 1) {
      return -1;
    }

    std::vector<int> memo(idx.size(), -1);
    return minOperations(std::span{idx}, x, &memo) / 2;
  }

private:
  static int minOperations(std::span<const int> idx, int x,
                           std::vector<int> *memo) {
    if (idx.empty()) {
      return 0;
    }
    if (idx.size() == 1) {
      return x;
    }
    auto &ops = (*memo)[idx.size() - 1];
    if (ops == -1) {
      ops = std::min({
          x + minOperations(idx.subspan(1), x, memo),
          2 * idx[1] - 2 * idx[0] + minOperations(idx.subspan(2), x, memo),
      });
    }
    return ops;
  }
};

} // namespace memo

namespace dp {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int minOperations(std::string s1, std::string s2, int x) {
    std::vector<int> idx;
    for (int i = 0; i < std::ssize(s1); ++i) {
      if (s1[i] != s2[i]) {
        idx.push_back(i);
      }
    }

    if (idx.empty()) {
      return 0;
    }
    if (idx.size() & 1) {
      return -1;
    }

    std::vector<int> dp(idx.size() + 1);
    dp[idx.size() - 1] = x;
    for (int i = idx.size() - 2; i >= 0; --i) {
      dp[i] = std::min(x + dp[i + 1], 2 * idx[i + 1] - 2 * idx[i] + dp[i + 2]);
    }
    return dp[0] / 2;
  }
};

} // namespace dp

namespace optimized {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int minOperations(std::string s1, std::string s2, int x) {
    std::vector<int> idx;
    for (int i = 0; i < std::ssize(s1); ++i) {
      if (s1[i] != s2[i]) {
        idx.push_back(i);
      }
    }

    if (idx.empty()) {
      return 0;
    }
    if (idx.size() & 1) {
      return -1;
    }

    int a = x, b = 0;
    for (int i = 1; i < std::ssize(idx); ++i) {
      b = std::exchange(a, std::min(x + a, 2 * idx[i] - 2 * idx[i - 1] + b));
    }
    return a / 2;
  }
};

} // namespace optimized
