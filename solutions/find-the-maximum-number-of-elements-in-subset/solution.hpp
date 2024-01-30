#pragma once

#include <unordered_map>
#include <vector>

// Time: O(NlogM)
// Space: O(N)

class Solution {
public:
  static constexpr int kMax = 1'000'000'000;

  static int maximumLength(const std::vector<int> &nums) {
    std::unordered_map<int, int> cnt;
    for (auto num : nums) {
      ++cnt[num];
    }

    int ans = 0;
    for (const auto &[num, freq] : cnt) {
      if (num == 1) {
        ans = std::max(ans, freq - (freq % 2 == 0));
        continue;
      }

      int length = 0;
      for (long long x = num; x <= kMax && cnt.contains(x); x *= x) {
        length += 2;
        if (cnt[x] == 1) {
          break;
        }
      }
      ans = std::max(ans, length - (length % 2 == 0));
    }
    return ans;
  }
};
