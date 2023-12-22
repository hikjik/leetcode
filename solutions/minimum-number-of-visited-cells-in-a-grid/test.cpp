#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{3, 4, 2, 1}, {4, 2, 1, 1}, {2, 1, 1, 0}, {3, 4, 1, 0}},
          .expected = 3,
      },
      {
          .grid{{2, 1, 0}, {1, 0, 0}},
          .expected = -1,
      },

  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::minimumVisitedCells(grid);
    REQUIRE(expected == actual);
  }
}

TEST_CASE("Big") {
  const int m = 1, n = 100'000;
  std::vector grid(m, std::vector<int>(n, n / 2));
  grid[m - 1][n - 1] = 0;
  REQUIRE(3 == Solution::minimumVisitedCells(grid));
}
