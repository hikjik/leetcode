#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}},
          .expected = 7,
      },
      {
          .grid{{1, 2, 3}, {4, 5, 6}},
          .expected = 12,
      },
  };

  SECTION("Memoization") {
    for (const auto &[grid, expected] : test_cases) {
      const auto actual = memo::Solution::minPathSum(grid);
      REQUIRE(expected == actual);
    }
  }

  SECTION("DP") {
    for (const auto &[grid, expected] : test_cases) {
      const auto actual = dp::Solution::minPathSum(grid);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Inplace") {
    for (auto &[grid, expected] : test_cases) {
      const auto actual = inplace::Solution::minPathSum(grid);
      REQUIRE(expected == actual);
    }
  }
}
