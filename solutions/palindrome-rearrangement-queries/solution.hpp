#pragma once

#include <array>
#include <string>
#include <valarray>
#include <vector>

// Time: O(NA+QA)
// Space: O(NA)

class Solution {
public:
  static std::vector<bool>
  canMakePalindromeQueries(std::string s,
                           const std::vector<std::vector<int>> &queries) {
    std::vector<int> pd{0};
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      pd.push_back(pd.back() + (s[i] != s[j]));
    }

    std::vector<std::valarray<int>> pc(1, std::valarray<int>(26));
    for (auto c : s) {
      pc.push_back(pc.back());
      ++pc.back()[c - 'a'];
    }

    std::vector<bool> ans;
    const int n = s.size();
    for (const auto &q : queries) {
      const int l1 = q[0], r1 = q[1], l2 = q[2], r2 = q[3];
      if (pd[std::min(l1, n - 1 - r2)] ||
          pd.back() - pd[std::max(r1 + 1, n - l2)] ||
          n - 1 - r2 > r1 && pd[n - 1 - r2] - pd[r1 + 1] ||
          l1 > n - 1 - l2 && pd[l1] - pd[n - l2]) {
        ans.push_back(false);
      } else {
        std::valarray<int> f1 = pc[r1 + 1] - pc[l1], f2 = pc[r2 + 1] - pc[l2];
        if (l1 > n - 1 - r2) {
          f2 -= pc[std::min(l1, n - l2)] - pc[n - 1 - r2];
        }
        if (l2 > n - 1 - r1) {
          f1 -= pc[std::min(l2, n - l1)] - pc[n - 1 - r1];
        }
        if (n - l1 > r2 + 1) {
          f1 -= pc[n - l1] - pc[std::max(r2 + 1, n - 1 - r1)];
        }
        if (n - l2 > r1 + 1) {
          f2 -= pc[n - l2] - pc[std::max(r1 + 1, n - 1 - r2)];
        }
        ans.push_back((f1 >= 0 && f2 >= 0 && f1 == f2).min());
      }
    }
    return ans;
  }
};
