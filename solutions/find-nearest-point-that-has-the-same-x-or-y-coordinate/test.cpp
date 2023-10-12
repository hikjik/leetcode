#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int x;
    int y;
    std::vector<std::vector<int>> points;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .x = 3,
          .y = 4,
          .points{{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}},
          .expected = 2,
      },
      {
          .x = 3,
          .y = 4,
          .points{{3, 4}},
          .expected = 0,
      },
      {
          .x = 3,
          .y = 4,
          .points{{2, 3}},
          .expected = -1,
      },
  };

  for (const auto &[x, y, points, expected] : test_cases) {
    const auto actual = Solution::nearestValidPoint(x, y, points);
    REQUIRE(expected == actual);
  }
}
