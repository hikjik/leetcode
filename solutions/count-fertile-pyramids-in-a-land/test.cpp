#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 1, 1, 1, 0},
                {1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1},
                {0, 1, 0, 0, 1}},
          .expected = 13,
      },
      {
          .grid{{0, 1, 1, 0}, {1, 1, 1, 1}},
          .expected = 2,
      },
      {
          .grid{{1, 1, 1}, {1, 1, 1}},
          .expected = 2,
      },
  };

  SECTION("Optimized") {
    for (const auto &[grid, expected] : test_cases) {
      const auto actual = optimized::Solution::countPyramids(grid);
      REQUIRE(expected == actual);
    }
  }

  SECTION("DP") {
    for (const auto &[grid, expected] : test_cases) {
      const auto actual = dp::Solution::countPyramids(grid);
      REQUIRE(expected == actual);
    }
  }
}
