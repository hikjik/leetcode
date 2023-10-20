#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 2}, {3, 4}},
          .expected = 17,
      },
      {
          .grid{{2}},
          .expected = 5,
      },
      {
          .grid{{1, 0}, {0, 2}},
          .expected = 8,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::projectionArea(grid);
    REQUIRE(expected == actual);
  }
}
