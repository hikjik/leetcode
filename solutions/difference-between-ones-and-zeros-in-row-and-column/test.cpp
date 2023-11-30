#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{0, 1, 1}, {1, 0, 1}, {0, 0, 1}},
          .expected{{0, 0, 4}, {0, 0, 4}, {-2, -2, 2}},
      },
      {
          .grid{{1, 1, 1}, {1, 1, 1}},
          .expected{{5, 5, 5}, {5, 5, 5}},
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::onesMinusZeros(grid);
    REQUIRE(expected == actual);
  }
}
