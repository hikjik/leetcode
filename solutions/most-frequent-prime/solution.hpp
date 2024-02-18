#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N^2M^2K^(0.5))
// Space: O(1)

class Solution {
public:
  static int mostFrequentPrime(const std::vector<std::vector<int>> &mat) {
    static const std::vector<std::pair<int, int>> kDirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    const int m = mat.size(), n = mat.back().size();

    std::unordered_map<int, int> cnt;
    int maxFreq = 0;
    int ans = -1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (const auto &[di, dj] : kDirs) {
          auto num = mat[i][j];
          for (auto r = i + di, c = j + dj; r >= 0 && c >= 0 && r < m && c < n;
               r += di, c += dj) {
            num = num * 10 + mat[r][c];
            if (isPrime(num)) {
              ++cnt[num];
              if (cnt[num] > maxFreq || (cnt[num] == maxFreq && num > ans)) {
                maxFreq = cnt[num];
                ans = num;
              }
            }
          }
        }
      }
    }
    return ans;
  }

private:
  static bool isPrime(int n) {
    if (n == 2) {
      return true;
    }
    if (n < 2 || !(n & 1)) {
      return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
};
