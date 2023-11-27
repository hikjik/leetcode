#pragma once

#include <array>
#include <numeric>
#include <vector>

// Time: O(logN)
// Space: O(1)

namespace dp {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int knightDialer(int n) {
    static const int kMod = 1e9 + 7;
    static const std::vector<std::vector<int>> kGraph{
        {4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
        {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

    std::vector dp(2, std::vector<int>(10, 1));
    while (--n) {
      for (int j = 0; j < 10; ++j) {
        dp[1][j] = 0;
        for (auto k : kGraph[j]) {
          dp[1][j] = (dp[1][j] + dp[0][k]) % kMod;
        }
      }
      dp[0].swap(dp[1]);
    }
    return std::accumulate(dp[0].cbegin(), dp[0].cend(), 0LL) % kMod;
  }
};

} // namespace dp

namespace symmetry {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  // A B A
  // C E C
  // A B A
  //   D
  //
  // A = 4, B = 2, C = 2, D = 1
  // A = 2 * (B + C), B = A, C = A + 2 * D, D = C
  static const int kMod = 1e9 + 7;

  static int knightDialer(int n) {
    if (n == 1) {
      return 10;
    }

    std::array<long long, 4> dp{4, 2, 2, 1};
    while (--n) {
      dp = {
          2 * (dp[1] + dp[2]) % kMod,
          dp[0],
          (dp[0] + 2 * dp[3]) % kMod,
          dp[2],
      };
    }
    return (dp[0] + dp[1] + dp[2] + dp[3]) % kMod;
  }
};

} // namespace symmetry

namespace la {

// Time: O(logN)
// Space: O(1)
class Solution {
private:
  using Matrix = std::array<std::array<long long, 10>, 10>;

  static constexpr int kMod = 1e9 + 7;
  static constexpr inline Matrix kAdj{{{0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                                       {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
                                       {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                                       {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                                       {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}}};

public:
  static int knightDialer(int n) {
    long long ans = 0;
    for (const auto &row : pow(kAdj, n - 1)) {
      ans += std::accumulate(row.begin(), row.end(), 0LL);
    }
    return ans % kMod;
  }

private:
  static Matrix pow(Matrix mat, int n) {
    Matrix c{};
    for (int i = 0; i < 10; ++i) {
      c[i][i] = 1;
    }
    for (int i = n; i; i >>= 1) {
      if (i & 1) {
        c = multiply(c, mat);
      }
      mat = multiply(mat, mat);
    }
    return c;
  }

  static Matrix multiply(const Matrix &a, const Matrix &b) {
    Matrix c{};
    for (int i = 0; i < std::ssize(a); ++i) {
      for (int j = 0; j < std::ssize(b[0]); ++j) {
        for (int k = 0; k < std::ssize(b); ++k) {
          c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % kMod;
        }
      }
    }
    return c;
  }
};

} // namespace la

namespace la_symmetry {

// Time: O(logN)
// Space: O(1)
class Solution {
private:
  template <size_t M, size_t N>
  using Matrix = std::array<std::array<long long, N>, M>;

  static constexpr int kMod = 1e9 + 7;

public:
  static int knightDialer(int n) {
    if (n == 1) {
      return 10;
    }

    Matrix<4, 4> mat{{
        {0, 1, 1, 0},
        {2, 0, 0, 0},
        {2, 0, 0, 1},
        {0, 0, 2, 0},
    }};
    Matrix<1, 4> vec{{
        {4, 2, 2, 1},
    }};

    for (int i = n - 1; i; i >>= 1) {
      if (i & 1) {
        vec = multiply(vec, mat);
      }
      mat = multiply(mat, mat);
    }
    return std::accumulate(vec[0].begin(), vec[0].end(), 0LL) % kMod;
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

} // namespace la_symmetry
