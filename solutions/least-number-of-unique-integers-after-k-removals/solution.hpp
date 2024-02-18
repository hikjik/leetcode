#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace sorting {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int findLeastNumOfUniqueInts(const std::vector<int> &nums, int k) {
    std::unordered_map<int, int> map;
    for (auto num : nums) {
      ++map[num];
    }
    std::vector<int> freq;
    for (const auto &[_, f] : map) {
      freq.push_back(f);
    }
    std::ranges::sort(freq);

    for (int i = 0; i < std::ssize(freq); ++i) {
      if (k >= freq[i]) {
        k -= freq[i];
      } else {
        return freq.size() - i;
      }
    }
    return 0;
  }
};

} // namespace sorting

namespace counting {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int findLeastNumOfUniqueInts(const std::vector<int> &nums, int k) {
    std::unordered_map<int, int> map;
    for (auto num : nums) {
      ++map[num];
    }

    const int n = nums.size();
    std::vector<int> freq(n + 1);
    for (const auto &[_, f] : map) {
      ++freq[f];
    }

    int ans = map.size();
    for (int i = 1; i <= n; ++i) {
      const auto m = std::min(k / i, freq[i]);
      k -= i * m;
      ans -= m;
    }
    return ans;
  }
};

} // namespace counting
