#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> obstacleGrid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
          .expected = 2,
      },
      {
          .obstacleGrid{{0, 1}, {0, 0}},
          .expected = 1,
      },
  };

  SECTION("Memoization") {
    for (const auto &[obstacleGrid, expected] : test_cases) {
      const auto actual =
          memo::Solution::uniquePathsWithObstacles(obstacleGrid);
      REQUIRE(expected == actual);
    }
  }

  SECTION("DP") {
    for (const auto &[obstacleGrid, expected] : test_cases) {
      const auto actual = dp::Solution::uniquePathsWithObstacles(obstacleGrid);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[obstacleGrid, expected] : test_cases) {
      const auto actual =
          optimized::Solution::uniquePathsWithObstacles(obstacleGrid);
      REQUIRE(expected == actual);
    }
  }
}
