#pragma once

#include <bit>
#include <functional>
#include <string>
#include <unordered_map>

// Time: O(N)
// Space: O(N)

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

namespace ps {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int maxPartitionsAfterOperations(std::string s, int k) {
    const int n = s.size();

    std::vector<int> prefix(n + 1);
    std::vector<unsigned> prefixMask(n + 1);
    for (int i = 0; i < n; ++i) {
      const auto mask = 1 << (s[i] - 'a');
      prefix[i + 1] = prefix[i];
      prefixMask[i + 1] = prefixMask[i] | mask;
      if (std::popcount(prefixMask[i + 1]) > k) {
        ++prefix[i + 1];
        prefixMask[i + 1] = mask;
      }
    }

    std::vector<int> suffix(n + 1);
    std::vector<unsigned> suffixMask(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      const auto mask = 1 << (s[i] - 'a');
      suffix[i] = suffix[i + 1];
      suffixMask[i] = suffixMask[i + 1] | mask;
      if (std::popcount(suffixMask[i]) > k) {
        ++suffix[i];
        suffixMask[i] = mask;
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      if (std::popcount(prefixMask[i] | suffixMask[i + 1]) < k) {
        cnt = 1;
      } else if (std::popcount(prefixMask[i]) == k &&
                 std::popcount(suffixMask[i + 1]) == k &&
                 std::popcount(prefixMask[i] | suffixMask[i + 1]) < 26) {
        cnt = 3;
      } else {
        cnt = 2;
      }
      ans = std::max(ans, prefix[i] + suffix[i + 1] + cnt);
    }
    return ans;
  }
};

} // namespace ps
