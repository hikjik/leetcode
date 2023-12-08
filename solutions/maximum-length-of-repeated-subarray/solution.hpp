#pragma once

#include <unordered_map>
#include <vector>

// Time: O(NMlog min(N,M))
// Space: O(M+N)

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int findLength(const std::vector<int> &nums1,
                        const std::vector<int> &nums2) {
    const int n = nums1.size(), m = nums2.size();
    std::vector dp(n + 1, std::vector<int>(m + 1));
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        if (nums1[i] == nums2[j]) {
          dp[i][j] = 1 + dp[i + 1][j + 1];
          ans = std::max(ans, dp[i][j]);
        }
      }
    }
    return ans;
  }
};

} // namespace dp

namespace optimized {

// Time: O(NM)
// Space: O(min(M,N))
class Solution {
public:
  static int findLength(const std::vector<int> &nums1,
                        const std::vector<int> &nums2) {
    const int n = nums1.size(), m = nums2.size();
    if (n < m) {
      return findLength(nums2, nums1);
    }

    std::vector<int> dp(m + 1);
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < m; ++j) {
        dp[j] = nums1[i] == nums2[j] ? 1 + dp[j + 1] : 0;
        ans = std::max(ans, dp[j]);
      }
    }
    return ans;
  }
};

} // namespace optimized

namespace hash {

// Time: O(NMlog min(N,M))
// Space: O(M+N)
class Solution {
private:
  static constexpr int kMod = 1e9 + 7;
  static constexpr int kPrime = 33;
  static constexpr int kPrimeInv = 939393946;

  static int mul(long long a, long long b) { return a * b % kMod; }
  static int sum(long long a, long long b) { return (a + b + kMod) % kMod; }

public:
  static int findLength(const std::vector<int> &nums1,
                        const std::vector<int> &nums2) {
    const int n = nums1.size(), m = nums2.size();

    std::vector<int> pows(std::max(n, m) + 1, 1);
    for (int i = 1; i < std::ssize(pows); ++i) {
      pows[i] = mul(pows[i - 1], kPrime);
    }
    std::vector<int> invs(std::max(n, m) + 1, 1);
    for (int i = 1; i < std::ssize(invs); ++i) {
      invs[i] = mul(invs[i - 1], kPrimeInv);
    }

    std::vector<int> prefix1(n + 1);
    for (int i = 0; i < n; ++i) {
      prefix1[i + 1] = sum(prefix1[i], mul(nums1[i], pows[i]));
    }
    std::vector<int> prefix2(m + 1);
    for (int i = 0; i < m; ++i) {
      prefix2[i + 1] = sum(prefix2[i], mul(nums2[i], pows[i]));
    }

    int left = 0, right = std::min(n, m);
    while (left < right) {
      const auto middle = left + (right - left + 1) / 2;

      std::unordered_map<int, int> seen;
      for (int i = 0; i + middle - 1 < n; ++i) {
        const auto hash = mul(sum(prefix1[i + middle], -prefix1[i]), invs[i]);
        seen[hash] = i;
      }

      bool ok = false;
      for (int i = 0; i + middle - 1 < m; ++i) {
        const auto hash = mul(sum(prefix2[i + middle], -prefix2[i]), invs[i]);
        if (seen.contains(hash) &&
            std::equal(nums2.begin() + i, nums2.begin() + i + middle,
                       nums1.begin() + seen[hash])) {
          ok = true;
          break;
        }
      }

      ok ? left = middle : right = middle - 1;
    }
    return left;
  }
};

} // namespace hash
