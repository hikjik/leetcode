#pragma once

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int numFactoredBinaryTrees(std::vector<int> arr) {
    std::sort(arr.begin(), arr.end());

    std::unordered_map<int, int> indexes;
    for (int i = 0; i < std::ssize(arr); ++i) {
      indexes[arr[i]] = i;
    }

    std::vector<long long> dp(arr.size(), 1);
    for (int i = 1; i < std::ssize(arr); ++i) {
      for (int j = 0; j < i; ++j) {
        if (arr[j] > std::sqrt(arr[i])) {
          break;
        }
        if (arr[i] % arr[j] != 0) {
          continue;
        }
        if (auto it = indexes.find(arr[i] / arr[j]); it != indexes.end()) {
          const int k = it->second;
          dp[i] += (k == j ? 1 : 2) * dp[j] * dp[k];
          dp[i] %= kMod;
        }
      }
    }

    return std::accumulate(dp.begin(), dp.end(), 0LL) % kMod;
  }
};
