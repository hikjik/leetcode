#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int row;
    int col;
    std::vector<std::vector<int>> cells;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .row = 2,
          .col = 2,
          .cells{{1, 1}, {2, 1}, {1, 2}, {2, 2}},
          .expected = 2,
      },
      {
          .row = 2,
          .col = 2,
          .cells{{1, 1}, {1, 2}, {2, 1}, {2, 2}},
          .expected = 1,
      },
      {
          .row = 3,
          .col = 3,
          .cells{{1, 2},
                 {2, 1},
                 {3, 3},
                 {2, 2},
                 {1, 1},
                 {1, 3},
                 {2, 3},
                 {3, 2},
                 {3, 1}},
          .expected = 3,
      },
  };

  for (const auto &[row, col, cells, expected] : test_cases) {
    const auto actual = Solution::latestDayToCross(row, col, cells);
    REQUIRE(expected == actual);
  }
}
