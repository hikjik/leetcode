#include <catch.hpp>

#include <solution.hpp>

bool IsPeak(const std::vector<int> &peak,
            const std::vector<std::vector<int>> &mat) {
  static std::vector<std::pair<int, int>> dirs{
      {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  int m = mat.size(), n = mat.back().size();
  int i = peak[0], j = peak[1];
  for (const auto &[di, dj] : dirs) {
    int r = i + di, c = j + dj;
    if (0 <= r && r < m && 0 <= c && c < n && mat[i][j] <= mat[r][c]) {
      return false;
    }
  }
  return true;
}

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{1, 4}, {3, 2}},
          .expected{0, 1},
      },
      {
          .mat{{10, 20, 15}, {21, 30, 14}, {7, 16, 32}},
          .expected{1, 1},
      },
  };

  for (const auto &[mat, expected] : test_cases) {
    const auto actual = Solution::findPeakGrid(mat);
    REQUIRE(IsPeak(actual, mat));
  }
}
