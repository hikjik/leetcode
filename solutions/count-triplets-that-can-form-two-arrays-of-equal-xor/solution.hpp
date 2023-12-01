#pragma once

#include <numeric>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace prefix_sum {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static int countTriplets(const std::vector<int> &arr) {
    std::vector<int> ps(arr.size() + 1);
    std::partial_sum(arr.begin(), arr.end(), ps.begin() + 1, std::bit_xor{});

    int ans = 0;
    for (int i = 0; i < std::ssize(ps); ++i) {
      for (int j = 0; j < i; ++j) {
        if (ps[i] == ps[j]) {
          ans += i - j - 1;
        }
      }
    }
    return ans;
  }
};

} // namespace prefix_sum

namespace hash_table {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int countTriplets(const std::vector<int> &arr) {
    int ps = 0;
    std::unordered_map<int, int> cnt{{ps, 1}};
    std::unordered_map<int, int> sum{{ps, -1}};

    int ans = 0;
    for (int i = 0; i < std::ssize(arr); ++i) {
      ps ^= arr[i];
      if (cnt.contains(ps)) {
        ans += i * cnt[ps] - sum[ps] - cnt[ps];
      }
      cnt[ps] += 1;
      sum[ps] += i;
    }
    return ans;
  }
};

} // namespace hash_table
