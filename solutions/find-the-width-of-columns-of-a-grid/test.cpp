#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1}, {22}, {333}},
          .expected{3},
      },
      {
          .grid{{-15, 1, 3}, {15, 7, 12}, {5, 6, -2}},
          .expected{3, 1, 2},
      },
      {
          .grid{{0}},
          .expected{1},
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::findColumnWidth(grid);
    REQUIRE(expected == actual);
  }
}
