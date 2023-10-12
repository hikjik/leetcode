#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}},
          .expected = 8,
      },
      {
          .grid{{3, 2}, {1, 0}},
          .expected = 0,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::countNegatives(grid);
    REQUIRE(expected == actual);
  }
}
