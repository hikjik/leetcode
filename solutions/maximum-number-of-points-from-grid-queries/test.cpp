#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    std::vector<int> queries;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 2, 3}, {2, 5, 7}, {3, 5, 1}},
          .queries{5, 6, 2},
          .expected{5, 8, 1},
      },
      {
          .grid{{5, 2, 1}, {1, 1, 2}},
          .queries{3},
          .expected{0},
      },
  };

  for (const auto &[grid, queries, expected] : test_cases) {
    const auto actual = Solution::maxPoints(grid, queries);
    REQUIRE(expected == actual);
  }
}
