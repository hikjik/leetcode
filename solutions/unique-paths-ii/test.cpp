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

  for (const auto &[obstacleGrid, expected] : test_cases) {
    const auto actual = Solution::uniquePathsWithObstacles(obstacleGrid);
    REQUIRE(expected == actual);
  }
}
