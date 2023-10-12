#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> points;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .points{{10, 16}, {2, 8}, {1, 6}, {7, 12}},
          .expected = 2,
      },
      {
          .points{{1, 2}, {3, 4}, {5, 6}, {7, 8}},
          .expected = 4,
      },
      {
          .points{{1, 2}, {2, 3}, {3, 4}, {4, 5}},
          .expected = 2,
      },
  };

  for (const auto &[points, expected] : test_cases) {
    const auto actual = Solution::findMinArrowShots(points);
    REQUIRE(expected == actual);
  }
}
