#pragma once

#include <numeric>
#include <ranges>
#include <unordered_map>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int minSetSize(const std::vector<int> &arr) {
    std::unordered_map<int, int> counter;
    for (auto num : arr) {
      ++counter[num];
    }

    std::vector<int> ps;
    for (const auto &[_, freq] : counter) {
      ps.push_back(freq);
    }
    std::ranges::sort(ps, std::greater{});
    std::partial_sum(ps.begin(), ps.end(), ps.begin());
    return std::ranges::lower_bound(ps, arr.size() / 2) - ps.begin() + 1;
  }
};
