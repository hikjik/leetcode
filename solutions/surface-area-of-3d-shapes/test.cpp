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
          .expected = 34,
      },
      {
          .grid{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
          .expected = 32,
      },
      {
          .grid{{2, 2, 2}, {2, 1, 2}, {2, 2, 2}},
          .expected = 46,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::surfaceArea(grid);
    REQUIRE(expected == actual);
  }
}
