#pragma once

#include <ranges>
#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int maximumSetSize(const std::vector<int> &nums1,
                            const std::vector<int> &nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());

    const auto countUnique = [](const auto &s1, const auto &s2) -> size_t {
      return std::ranges::count_if(s1, [&](int a) { return !s2.contains(a); });
    };

    const auto n = nums1.size(), m = n / 2;
    const auto uniq1 = std::min(m, countUnique(set1, set2));
    const auto uniq2 = std::min(m, countUnique(set2, set1));
    const auto common = set1.size() - countUnique(set1, set2);
    return uniq1 + uniq2 + std::min(n - uniq1 - uniq2, common);
  }
};
