#pragma once

#include <bit>
#include <functional>
#include <string>
#include <unordered_map>

// Time:
// Space:

namespace memo {

class Solution {
public:
  static int maxPartitionsAfterOperations(std::string s, int k) {
    std::unordered_map<long long, int> memo;

    std::function<int(long long, int, unsigned)> maxPartitions;
    maxPartitions = [&](long long i, int ops, unsigned mask) {
      if (i == std::ssize(s)) {
        return 0;
      }
      const auto key = (i << 27) | (mask << 1) | ops;
      if (auto it = memo.find(key); it != memo.end()) {
        return it->second;
      }

      int ans = 0;
      const auto j = s[i] - 'a';
      if (std::popcount(mask | 1 << j) > k) {
        ans = 1 + maxPartitions(i + 1, ops, 1 << j);
      } else {
        ans = maxPartitions(i + 1, ops, mask | 1 << j);
      }

      if (ops) {
        for (int j = 0; j < 26; ++j) {
          if (std::popcount(mask | 1 << j) > k) {
            ans = std::max(ans, 1 + maxPartitions(i + 1, 0, 1 << j));
          } else {
            ans = std::max(ans, maxPartitions(i + 1, 0, mask | 1 << j));
          }
        }
      }

      return memo[key] = ans;
    };

    return 1 + maxPartitions(0, 1, 0);
  }
};

} // namespace memo
