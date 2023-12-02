#pragma once

#include <array>

// Time: O(logN)
// Space: O(1)

namespace dp {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int numOfWays(int n) {
    std::array<long long, 2> dp{6, 6};
    while (--n) {
      dp = {
          (dp[0] * 3 + dp[1] * 2) % kMod,
          (dp[0] * 2 + dp[1] * 2) % kMod,
      };
    }
    return (dp[0] + dp[1]) % kMod;
  }
};

} // namespace dp

namespace algebra {

// Time: O(logN)
// Space: O(1)
class Solution {
private:
  template <size_t M, size_t N>
  using Matrix = std::array<std::array<long long, N>, M>;

  static constexpr int kMod = 1e9 + 7;

public:
  static int numOfWays(int n) {
    Matrix<2, 2> mat{{{3, 2}, {2, 2}}};
    Matrix<1, 2> vec{{{6, 6}}};
    for (int i = n - 1; i; i >>= 1) {
      if (i & 1) {
        vec = multiply(vec, mat);
      }
      mat = multiply(mat, mat);
    }
    return (vec[0][0] + vec[0][1]) % kMod;
  }

private:
  template <size_t N, size_t K, size_t M>
  static Matrix<N, M> multiply(const Matrix<N, K> &a, const Matrix<K, M> &b) {
    Matrix<N, M> c{};
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = 0; j < M; ++j) {
        for (size_t k = 0; k < K; ++k) {
          c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % kMod;
        }
      }
    }
    return c;
  }
};

} // namespace algebra
