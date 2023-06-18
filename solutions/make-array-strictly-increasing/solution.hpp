#pragma once

#include <algorithm>
#include <limits>
#include <unordered_map>
#include <vector>

class Solution {
private:
  static inline const int kInf = std::numeric_limits<int>::max();

public:
  static int makeArrayIncreasing(const std::vector<int> &arr1,
                                 std::vector<int> arr2) {
    std::sort(arr2.begin(), arr2.end());

    std::unordered_map<int, int> dp{{-1, 0}};
    for (auto a : arr1) {
      std::unordered_map<int, int> new_dp;
      for (const auto &[value, steps] : dp) {
        if (a > value) {
          new_dp[a] = std::min(new_dp.count(a) ? new_dp[a] : kInf, steps);
        }

        auto it = std::upper_bound(arr2.begin(), arr2.end(), value);
        if (it != arr2.end()) {
          new_dp[*it] =
              std::min(new_dp.count(*it) ? new_dp[*it] : kInf, steps + 1);
        }
      }
      dp.swap(new_dp);
    }

    int cnt = kInf;
    for (const auto &[_, steps] : dp) {
      cnt = std::min(cnt, steps);
    }
    return cnt == kInf ? -1 : cnt;
  }
};
