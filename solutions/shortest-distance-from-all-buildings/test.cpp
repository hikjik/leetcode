#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 0, 2, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}},
          .expected = 7,
      },
      {
          .grid{{1, 0}},
          .expected = 1,
      },
      {
          .grid{{1}},
          .expected = -1,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::shortestDistance(grid);
    REQUIRE(expected == actual);
  }
}
