#pragma once

#include <vector>

// Time: O(N+M)
// Space: O(M)

class Solution {
public:
  static int countMatchingSubarrays(const std::vector<int> &nums,
                                    const std::vector<int> &pattern) {
    const int n = nums.size() - 1, m = pattern.size();
    const auto lps = LPS(pattern);

    int ans = 0;
    for (int i = 0, j = 0; i < n;) {
      const auto value = (nums[i + 1] > nums[i]) - (nums[i + 1] < nums[i]);
      if (value == pattern[j]) {
        i++, j++;
        if (j == m) {
          ++ans;
          j = lps[j - 1];
        }
      } else {
        if (j) {
          j = lps[j - 1];
        } else {
          ++i;
        }
      }
    }
    return ans;
  }

private:
  static std::vector<int> LPS(const std::vector<int> &s) {
    std::vector<int> lps(s.size());
    for (int i = 1, j = 0; i < std::ssize(s);) {
      if (s[i] == s[j]) {
        lps[i++] = ++j;
      } else {
        if (j) {
          j = lps[j - 1];
        } else {
          ++i;
        }
      }
    }
    return lps;
  }
};
